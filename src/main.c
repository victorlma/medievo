#include "locdef.h"    // Localization Strings for simple translation support
#include "raylib.h"

#include "gameobjects.h"

void DrawEntities()
{
}

void GameUpdateRender()
{
        BeginDrawing();


        DrawEntities();


        EndDrawing();
}

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(800, 600, locGAME_TITLE);

    while (!WindowShouldClose()) {

        GameUpdateRender();

    }

    CloseWindow();
    return 0;
}
