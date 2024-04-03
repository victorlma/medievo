#include "raylib.h"





int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(800, 600, "Test");

    while (!WindowShouldClose()) {

        BeginDrawing();
        EndDrawing();

    }

    CloseWindow();
    return 0;
}
