#include <stdio.h>
#include "raylib.h"
#include "character.h"
#include "constants.h"

int x = SCREEN_WIDTH / 2;
int y = SCREEN_HEIGHT / 2;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Better Doodle Jump");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        drawCharacter(x, y, 20, 20);
        EndDrawing();
    }
    return 0;
}