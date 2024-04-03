#include "locdef.h"    // Localization Strings for simple translation support
#include "stdlib.h"
#include "raylib.h"
#include "raymath.h"

#include "gameobjects.h"

void DrawEntities(gameMemory  *gm)
{
    entities *entTable = &(gm->entTable);

    for (int id=0; id < entTable->used; ++id)
    {
        if (entTable->state[id] !=0) {
            DrawRectangleRec(
                    (Rectangle) {
                    entTable->pos[id].x,
                    entTable->pos[id].y,
                    entTable->size[id],
                    entTable->size[id]
                    },
                    gm->entColors[entTable->type[id]]);
        }
    }
}

void MoveEntity(gameMemory *gm, int id, Vector2 mv)
{
    entities *entTable = &(gm->entTable);

    mv = Vector2Scale(mv, entTable->speed[id]);

    entTable->pos[id].x += mv.x;
    entTable->pos[id].y += mv.y;

}

void ProcessInput(gameMemory *gm, float dt)
{
    controller *plc = &(gm->plc);

    Vector2 mv = (Vector2) {0};

    if (IsKeyDown(plc->u)) mv.y -=1;
    if (IsKeyDown(plc->d)) mv.y +=1;
    if (IsKeyDown(plc->l)) mv.x -=1;
    if (IsKeyDown(plc->r)) mv.x +=1;

    mv = Vector2Normalize(mv);
    mv = Vector2Scale(mv, dt);

    if (Vector2Length(mv) != 0) MoveEntity(gm, PLAYER, mv);

}

void GameUpdateRender(gameMemory  *gm)
{

    float dt = GetFrameTime();
    ProcessInput(gm, dt);

    BeginDrawing();
    ClearBackground(RAYWHITE);


        DrawEntities(gm);


    EndDrawing();
}

void AddEntity(gameMemory *gm, int type, Vector2 pos, float size, float speed)
{
    entities *entTable = &gm->entTable;

    if (entTable->used < MAX_ENT) {
        entTable->state[entTable->used] = 1;
        entTable->type[entTable->used] = type;
        entTable->pos[entTable->used] = pos;
        entTable->size[entTable->used] = size;
        entTable->speed[entTable->used] = speed;
        ++entTable->used;
    }
}

void SetupGameMemory(gameMemory *gm)
{
    gm->plc.u = KEY_W;
    gm->plc.d = KEY_S;
    gm->plc.l = KEY_A;
    gm->plc.r = KEY_D;



    gm->plc.au = KEY_I;
    gm->plc.ad = KEY_K;
    gm->plc.al = KEY_J;
    gm->plc.ar = KEY_L;


    gm->entColors[PLAYER] = BLUE;
    gm->entColors[ENEMY] = RED;
    gm->entColors[ALLY] = PURPLE;
    gm->entColors[ABUILDING] = DARKBLUE;
    gm->entColors[EBUILDING] = DARKBROWN;

    AddEntity(gm,
              PLAYER,
              (Vector2) {200,200},
              20, 400);

    AddEntity(gm,
              ENEMY,
              (Vector2) {200,100},
              20, 20);
    AddEntity(gm,
              ALLY,
              (Vector2) {200,300},
              20, 20);
    AddEntity(gm,
              ABUILDING,
              (Vector2) {100,400},
              30, 20);
    AddEntity(gm,
              EBUILDING,
              (Vector2) {100,0},
              30, 20);
}

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(800, 600, locGAME_TITLE);


    gameMemory *gm = malloc(sizeof(gameMemory));
    *gm = (gameMemory) {0};
    SetupGameMemory(gm);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        GameUpdateRender(gm);

    }

    free(gm);
    CloseWindow();
    return 0;
}
