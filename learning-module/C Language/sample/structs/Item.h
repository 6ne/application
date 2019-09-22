#pragma once

struct Item {
  char name[255];
  char size;
  char category[255];
  int value;
  int amount;
};

struct Item generateItem (FILE *file) {
  Item item;
  fscanf(file, "%[^#]#%c#%[^#]#%d\n",
    &item.name,
    &item.size,
    &item.category,
    &item.value
  );

  item.amount = 1;

  return item;
}