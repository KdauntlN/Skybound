#include <stdio.h>
#include "raylib.h"
#include "character.h"
#include "constants.h"

int main() {
    SetTargetFPS(60);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Better Doodle Jump");

    Color colourList[] = {
        RED,
        ORANGE,
        YELLOW,
        GREEN,
        BLUE,
        PINK,
        PURPLE
    };
    
    int numColours = sizeof(colourList) / sizeof(colourList[0]);

    int colourIndex = 0;
    Color currentColour = colourList[colourIndex];

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_SPACE)) {
            colourIndex = (colourIndex + 1) % numColours;
            currentColour = colourList[colourIndex];
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (GetFPS() < 100) {
            drawCharacter(20, 20, currentColour);
        }

        DrawFPS(10, 10);
        EndDrawing();
    }
    return 0;
}