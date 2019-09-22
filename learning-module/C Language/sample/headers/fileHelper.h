#pragma once

#define _PROFILE_DATA_FILE "data/user/profile.dat"
#define _BAG_DATA_FILE "data/user/bag.dat"
#define _INVENTORY_DATA_FILE "data/user/inventory.dat"
#define _ENEMY_DATA_FILE "data/game/enemies.dat"
#define _ITEM_DATA_FILE "data/game/items.dat"
#define _MAP_DATA_FILE "data/game/map.dat"

int isFileEmpty(FILE *file) {
  fseek(file, 0, SEEK_END);

  long size = ftell(file);

  return size == 0;
}

int isFileNotFound(FILE *file) { return file == NULL; }

FILE *readMapData () { return fopen(_MAP_DATA_FILE, "r"); }

FILE *readProfileData () { return fopen(_PROFILE_DATA_FILE, "r"); }

FILE *writeProfileData () { return fopen(_PROFILE_DATA_FILE, "w"); }

FILE *readBagData () { return fopen(_BAG_DATA_FILE, "r"); }

FILE *writeBagData () { return fopen(_BAG_DATA_FILE, "w"); }

FILE *readInventoryData () { return fopen(_INVENTORY_DATA_FILE, "r"); }

FILE *writeInventoryData () { return fopen(_INVENTORY_DATA_FILE, "w"); }

FILE *readEnemyData () { return fopen(_ENEMY_DATA_FILE, "r"); }

FILE *readItemData () { return fopen(_ITEM_DATA_FILE, "r"); }

void createNewProfileFile(char *name) {
  FILE *file = writeProfileData();
  fprintf(file, "%s#1#0#100#5#5#0\n", name);
  fclose(file);
}

void createNewBagFile() { fclose(writeBagData()); }

void createNewInventoryFile() { fclose(writeInventoryData()); }
