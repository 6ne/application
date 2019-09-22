/*
 * @Author: Clavin June
 * @File  : Helper function
 * @Desc  : A simple library used for simple game, function starts with '_' (underscore) means it's private function for this file only
*/
// ALIAS
#pragma once
#ifdef __linux__
  #include <unistd.h>
  #include "kbhit.h"
  #define KBHIT lkbhit
  #define GETCH lgetch
#else
  #include <windows.h>
  #include <conio.h>
  #define KBHIT kbhit
  #define GETCH getch
#endif

#define _FOR(a,b,c) for ( int a = b ; a < c ; ++a )
#define NEW_GAME 1
#define RESUME_GAME 0
#define BACK_TO_MAIN_MENU -1
#define ADVENTURE 1
#define MEDITATE 2
#define CHECK_BAG 3
#define SAVE_GAME 4
#define EXIT_GAME 5

#define MAP_W 20
#define MAP_H 10

double intervalBetween = .5;

void setIntervalBetween(double n) { intervalBetween = n; }

void clear () { _FOR(i,0,50) puts(""); }

void _sleep (double n) {
  #ifdef __linux__
    usleep(n * 1000000);
  #else
    Sleep(n);
  #endif
}

void showSplashScreen () {
  char banner[] = "\t\t\t\t  ____\n\t\t\t\t / ___| __ _ _ __ ___   ___ \n\t\t\t\t| |  _ / _` | '_ ` _ \\ / _ \\\n\t\t\t\t| |_| | (_| | | | | | |  __/\n\t\t\t\t \\____|\\__,_|_| |_| |_|\\___|\n";

 _FOR(i,0,143) {
   printf("%c", banner[i]); fflush(stdout);
   _sleep(intervalBetween);
 }
}

void showLoadingText () {
  _FOR(i,0,8) {
    char _[] = "-/|\\-/|\\";
    printf("\r%c", _[i]); fflush(stdout);
    _sleep(intervalBetween * 10);
  }
}

// @TODO
int move(int x, int y) {
  return 0;
}

int moveX (int x) {
  return 0;
}

int moveY (int y) {
  return 0;
}