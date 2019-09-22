#pragma once
#include "Item.h"

struct Player
{
  char name[255];
  int level;
  int experience;
  int health;
  int attack;
  int defense;
  int gold;
  Item items[100];
};

struct Player generatePlayer (FILE *file) {
  Player player;
  fscanf(file, "%[^#]#%d#%d#%d#%d#%d#%d\n",
    &player.name,
    &player.level,
    &player.experience,
    &player.health,
    &player.attack,
    &player.defense,
    &player.gold
  );

  return player;
}

void savePlayer(FILE *file, Player player) {
  fprintf(file, "%s#%d#%d#%d#%d#%d#%d\n",
    player.name,
    player.level,
    player.experience,
    player.health,
    player.attack,
    player.defense,
    player.gold
  );
}

void showPlayerStatus (Player player) {
  printf("Welcome, %s!\n", player.name);
  printf("Level: %d\n", player.level);
  printf("Exp: %d / %d\n", player.experience, player.level * 100);
  printf("Health: %d\n", player.health);
  printf("Gold: %d\n", player.gold);
}

void levelUp (Player &player) {
  player.level += 1;
  player.health += 50;
  player.attack += 5;
  player.defense += 5;
}

void addExp (Player &player, int exp) {
  player.experience += exp;

  if (player.experience >= player.level * 100) {
    player.experience -= (player.level * 100);
    levelUp(player);
    printf("Level UP! Current level: %d\n", player.level);
  }
}
