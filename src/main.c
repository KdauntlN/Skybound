#include <stdio.h>
#include "raylib.h"
#include "character.h"
#include "constants.h"

int main() {
<<<<<<< HEAD
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Better Doodle Jump");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (GetFPS() < 100) {
            drawCharacter(20, 20);
=======
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
>>>>>>> 38028f16df975f1e35995676c8b7f794b27481cf
        }

        DrawFPS(10, 10);
        EndDrawing();
    }
    return 0;
}