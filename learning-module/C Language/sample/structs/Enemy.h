#pragma once

struct Enemy
{
  char name[255];
  int health;
  int attack;
  int defense;
  int experience;
};

struct Enemy generateEnemy (FILE *file) {
  Enemy enemy;
  fscanf(file, "%[^#]#%d#%d#%d#%d\n",
    &enemy.name,
    &enemy.health,
    &enemy.attack,
    &enemy.defense,
    &enemy.experience
  );

  return enemy;
}