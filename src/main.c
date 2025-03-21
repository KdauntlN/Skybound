#include <stdio.h>
#include "raylib.h"
#include "character.h"
#include "constants.h"

int main() {
    SetTargetFPS(60);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Better Doodle Jump");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (GetFPS() < 100) {
            drawCharacter(20, 20);
        }

        DrawFPS(10, 10);
        EndDrawing();
    }
    return 0;
}