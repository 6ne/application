#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "fileHelper.h"
#include "gameHelper.h"
#include "promptHelper.h"
#include "../structs/Player.h"
#include "../structs/Enemy.h"

Player player;
Item globalItems[999];
Enemy enemies[999];
int totalGlobalItemsLoaded = 0;
int totalEnemiesLoaded = 0;
int totalPlayersItemLoaded = 0;

char adventureMap[MAP_H][MAP_W];

int loadGame () {
  int gameMode = RESUME_GAME;
  FILE *file = readProfileData();

  if (isFileNotFound(file) || isFileEmpty(file) ) {
    int isNewJourney = askForNewJourney();

    gameMode = isNewJourney ? NEW_GAME : BACK_TO_MAIN_MENU;
  }

  fclose(file);
  return gameMode;
}

void createNewPlayer (char *name) {
  createNewProfileFile(name);
  createNewInventoryFile();
  createNewBagFile();
}

void loadEnemies () {
  FILE *file = readEnemyData();

  while (!feof(file)) {
    enemies[totalEnemiesLoaded++] = generateEnemy(file);
  }
  puts("Enemy loaded.");
  _sleep(.5);

  fclose(file);
}

void loadItems () {
  FILE *file = readItemData();

  while (!feof(file)) {
    globalItems[totalGlobalItemsLoaded++] = generateItem(file);
  }
  puts("Item loaded.");
  _sleep(.5);

  fclose(file);
}

void loadPlayerProfile () {
  FILE *file = readProfileData();

  player = generatePlayer(file);

  fclose(file);

  file = readBagData();

  if (!isFileEmpty(file)) {
    while (!feof(file)) {
      player.items[totalPlayersItemLoaded++] = generateItem(file);
    }
  }

  // @TODO read inventory

  fclose(file);
}

void loadWorld () {
  loadEnemies();
  loadItems();

  puts("World Loaded.");
  _sleep(.5);

  loadPlayerProfile();
  showLoadingText();
}

void loadMap () {
  FILE *file = readMapData();
  int i = 0;
  while (!feof(file)) {
    fscanf(file, "%[^\n]\n", &adventureMap[i++]);
  }
  fclose(file);
}

void refreshMap (int x, int y) {
  _FOR(i,0,MAP_H) {
    _FOR(j,0,MAP_W) {
      if (x == i && y == j) printf("X");
      else
      printf("%c", adventureMap[i][j]);
    }
    puts("");
  }
}

void adventure () {
  // @TODO
  loadMap();

  int x = 1, y = 1;
  while (1) {
    clear();
    showPlayerStatus(player);
    puts("(Q)uit | (B)ag)");

    refreshMap(x, y);

    char c = GETCH();

    if (isMove(c)) {
      int random = rand() % 10;

      if (random >= 7) {
        // encounter enemy
      } else if (random >= 4) {
        int index = rand () % totalGlobalItemsLoaded;
        Item item = globalItems[index];
        printf("You've got %s(%c): %d pcs\n",
          item.name, item.size, item.amount);
      }

      if (isUp(c))         x = move(x+1, y);
      else if (isDown(c))  x = move(x-1, y);
      else if (isLeft(c))  y = move(x, y-1);
      else if (isRight(c)) y = move(x, y+1);
    }

    if (isQuit(c)) break;
  }
}

void meditate () {
  clear();
  puts("+==============+");
  puts("|   ZEN MODE   |");
  puts("+==============+");
  puts("Press any key to quit zen mode.");
  while (!KBHIT()) {
    _sleep(5);
    int random = rand() % 10 + 1;

    int expGained = (player.level * 100) * (rand() % 5+1) / 100;

    if (random == 10) expGained *= 2;

    printf("Exp gained %d!\n", expGained);

    addExp(player, expGained);
  }
}

void saveGame () {
  FILE *file = writeProfileData();
  savePlayer(file, player);
  fclose(file);

  // @TODO save bag save inventory

  puts("Game Saved!"); getchar();
}

void showWorld () {
  int menu = -1;

  do {
    clear();
    showPlayerStatus(player);
    menu = askForGameMenu();

    switch (menu) {
      case ADVENTURE: adventure();
        break;
      case MEDITATE: meditate();
        break;
      case CHECK_BAG:
        break;
      case SAVE_GAME: saveGame();
        break;
    }
  } while (menu != EXIT_GAME);
}

void play(int isNewGame) {
  if (isNewGame) {
    char name[255];
    askForPlayerName(name);

    createNewPlayer(name);
  }

  loadWorld();
  showWorld();
}