#include <stdio.h>
#include "raylib.h"
#include "character.h"
#include "constants.h"

int main() {
    SetTargetFPS(60);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Skybound");

    Texture2D jetpackOn1 = LoadTexture("assets/jetpack-on-1.png");
    Texture2D jetpackOn2 = LoadTexture("assets/jetpack-on-2.png");
    Texture2D jetpackOff = LoadTexture("assets/jetpack-off.png");

    float frameTime = 0.0f;
    int currentFrame = 0;

    while (!WindowShouldClose()) {
        frameTime += GetFrameTime();

        if (frameTime > 0.2f) {
            currentFrame = !currentFrame;
            frameTime = 0.0f;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        bool isJetpackOn = IsKeyDown(KEY_W);
        if (isJetpackOn) {
            drawCharacter(currentFrame ? jetpackOn2:jetpackOn1, 20, 20, WHITE);
        }
        else {
            drawCharacter(jetpackOff, 20, 20, WHITE);
        }
        EndDrawing();
    }

    UnloadTexture(jetpackOn1);
    UnloadTexture(jetpackOn2);
    UnloadTexture(jetpackOff);
    CloseWindow();
    return 0;
}