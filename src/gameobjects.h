#include "raylib.h"
#ifndef GAMEOBJECTS_H_
#define GAMEOBJECTS_H_

#define MAX_ENT  1000

typedef struct entities {
    int id[MAX_ENT];
    Vector2 pos[MAX_ENT];
    float size[MAX_ENT];
} entities;


typedef struct gameMemory {

    entities    entTable;

} gameMemory;

#endif
