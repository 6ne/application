#include <stdio.h>
#include "headers/game.h"

int main () {
  setIntervalBetween(0.0);
  srand(time(0));
  while (1) {
    clear();
    showSplashScreen();
    int menu = askForMainMenu();
    int gameMode = NEW_GAME;

    if (menu == 2) {
      gameMode = loadGame();
      if (gameMode == BACK_TO_MAIN_MENU) continue;
    } else if (menu == 3) {
      return 0;
    }

    clear();
    play(gameMode);
  }
}