#include "locdef.h"    // Localization Strings for simple translation support
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
