#include <stdio.h>
#include "raylib.h"

int main() {
    InitWindow(360, 480, "Better Doodle Jump");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    return 0;
}