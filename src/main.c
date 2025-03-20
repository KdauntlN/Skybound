#include <stdio.h>
#include "raylib.h"
#include "character.h"

const int screenwidth = 270;
const int screenheight = 480;

int main() {
    InitWindow(screenwidth, screenheight, "Better Doodle Jump");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    return 0;
}