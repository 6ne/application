#pragma once

int len(char *str) {
  int i = 0;
  while (str[i++]);
  return i;
}

int isUpper (char c) { return c >= 'A' && c <= 'Z'; }

int isLower (char c) { return c >= 'a' && c <= 'z'; }

int toUpper (char c) { return isLower(c) ? c - 32 : c; }

int toLower (char c) { return isUpper(c) ? c + 32 : c; }

int isYes (char c) { return toUpper(c) == 'Y'; }

int isNo (char c) { return toUpper(c) == 'N'; }

int isYesNo (char c) { return isYes(c) || isNo(c); }

int isUp (char c) { return toUpper(c) == 'W'; }

int isDown (char c) { return toUpper(c) == 'S'; }

int isLeft (char c) { return toUpper(c) == 'A'; }

int isRight (char c) { return toUpper(c) == 'D'; }

int isQuit (char c) { return toUpper(c) == 'Q'; }

int isBag (char c) { return toUpper(c) == 'B'; }

int isMove (char c) { return isRight(c) || isLeft(c) || isUp(c) || isDown(c); }

int askForNewJourney () {
  char prompt = 'Y';
  do {
    printf("\t\t\t    No Data. Start a new journey [Y/n] ? "); 
    scanf("%c", &prompt); getchar();
  } while ( !isYesNo(prompt) );

  return isYes(prompt);
}

int askForMainMenu () {
  int menu = -1;
  puts("\n\t\t\t\t1. New Game  2.Load  3. Exit");
  do {
    printf("\n\t\t\t\tChoose: "); 
    scanf("%d", &menu); getchar();
  } while (menu < 1 || menu > 3);

  return menu;
}

void askForPlayerName (char *name) {
  do {
    printf("Input your player name [5..15]: ");
    scanf("%[^\n]", name); getchar();
  } while (len(name) < 5 || len(name) > 15);
}


int askForGameMenu() {
  puts("+================+");
  puts("|      Menu      |");
  puts("|----------------|");
  puts("| 1. Adventure   |");
  puts("| 2. Meditate    |");
  puts("| 3. Check Bag   |");
  puts("| 4. Save Game   |");
  puts("| 5. Exit        |");
  puts("+================+");

  int menu = -1;
  do {
    printf("Choose: ");
    scanf("%d", &menu); getchar();
  } while ( menu < 1 || menu > 5 );

  return menu;
}