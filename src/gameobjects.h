#include "raylib.h"
#ifndef GAMEOBJECTS_H_
#define GAMEOBJECTS_H_

#define MAX_ENT  1000

typedef enum {
    PLAYER,
    ENEMY,
    ALLY,
    ABUILDING,
    EBUILDING,

    ENT_TYPE_COUNT

} ENTITY_TYPE;

typedef struct controller {

    int     u;
    int     d;
    int     l;
    int     r;

    int     au;
    int     ad;
    int     al;
    int     ar;

} controller;

typedef struct entities {
    int used;

    int state[MAX_ENT];
    int type[MAX_ENT];
    Vector2 pos[MAX_ENT];
    float size[MAX_ENT];
    float speed[MAX_ENT];

} entities;


typedef struct gameMemory {

    controller  plc;
    entities    entTable;
    Color       entColors[ENT_TYPE_COUNT];

} gameMemory;

#endif
