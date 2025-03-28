#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "raylib.h"

// Declare screen size constants
const int SCREEN_WIDTH = 270;
const int SCREEN_HEIGHT = 480;

// Global timekeeper variable
float timeSinceLastFrame;

// Timekeeper for player animation
float totalTime = 0;

// Create a struct to keep track of character values
typedef struct {

    // Declare variables related to positioning and movement
    float x, y;
    float vx, vy;
    int width, height;
    float speed;
    float gravity;
    float rotation;
    
    // Declare textures
    Texture2D jetpackOff;
    Texture2D jetpackOn1;
    Texture2D jetpackOn2;
    int textureNumber;

} Character;

Character initCharacter() {

    // Zero-initialise the character struct
    Character character = { 0 };

    // Define width and height
    character.width = 20;
    character.height = 20;

    // Place the character in the centre of the screen
    character.x = SCREEN_WIDTH / 2;
    character.y = SCREEN_HEIGHT / 2;

    // Define speed in x and y directions
    character.vx = 0;
    character.vy = 0;

    // Initialize remaining variables
    character.speed = 400;
    character.gravity = 200;
    character.rotation = 0;

    // Initialise textures
    character.jetpackOff = LoadTexture("assets/jetpack-off.png");
    character.jetpackOn1 = LoadTexture("assets/jetpack-on-1.png");
    character.jetpackOn2 = LoadTexture("assets/jetpack-on-2.png");

    // Check if the textures have loaded properly
    if (character.jetpackOff.id == 0 || character.jetpackOn1.id == 0 || character.jetpackOn2.id == 0) {
        printf("Error: Failed to load one or more textures\n");
        exit(1);
    }

    //Set texture to 0
    character.textureNumber = 0;

    // Return the character
    return character;
}

void drawCharacter(Character player) {

    if (IsKeyDown(KEY_W)) {
        DrawTexturePro(player.textureNumber ? player.jetpackOn1:player.jetpackOn2, (Rectangle) {0, 0, 20, 20}, (Rectangle) {player.x, player.y, player.width, player.height}, (Vector2) {player.width / 2, player.height / 2}, player.rotation, WHITE);
    } else {
        DrawTexturePro(player.jetpackOff, (Rectangle) {0, 0, 20, 20}, (Rectangle) {player.x, player.y, player.width, player.height}, (Vector2) {player.width / 2, player.height / 2}, player.rotation, WHITE);
    }
}

void updateCharacter(Character *player, float deltaTime) {

    // Move the player down due to gravity
    player->vy += player->gravity * deltaTime;

    if (IsKeyDown(KEY_A)) player->rotation -= 180 * deltaTime;
    if (IsKeyDown(KEY_D)) player->rotation += 180 * deltaTime;

    // Move the player if they're holding W
    if (IsKeyDown(KEY_W)) {
        
        // Move the player based off of their angle
        float rad = (player->rotation - 90) * (M_PI / 180);
        player->vy += sin(rad) * player->speed * deltaTime;
        player->vx += cos(rad) * player->speed * deltaTime;
    }

    player->y += player->vy * deltaTime;
    player->x += player->vx * deltaTime;

    totalTime += deltaTime;
        
    if (totalTime > 0.25) {
        player->textureNumber = !player->textureNumber;
        totalTime = 0;
    }
}

int main() {

    // Open the window
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Skybound");
    SetTargetFPS(60);

    // Create the player character
    Character player = initCharacter();

    // Keep the window open
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);  // Clear the screen

        timeSinceLastFrame = GetFrameTime();

        updateCharacter(&player, timeSinceLastFrame);
        drawCharacter(player);

        EndDrawing();
    }

    // Unload textures
    UnloadTexture(player.jetpackOff);
    UnloadTexture(player.jetpackOn1);
    UnloadTexture(player.jetpackOn2);

    CloseWindow();

    return 0;
}