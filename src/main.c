#include <stdio.h>
#include "raylib.h"
#include "character.h"
#include "constants.h"

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Better Doodle Jump");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    return 0;
}