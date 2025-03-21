#include "character.h"
#include "raylib.h"
#include "constants.h"

float x = SCREEN_WIDTH / 2;
float y = SCREEN_HEIGHT / 2;
float dx = 0;
float dy = 0;
float speed = 1;
float gravity = 0.5;

void drawCharacter(int width, int height) {
    DrawRectangle(x, y, width, height, RED);
    dy += gravity;
    y += dy;
    if (IsKeyDown(KEY_SPACE)) {
        dy -= 1;
    }
    if (dy > 50) {
        dy = 50;
    }
    if (dy < -20) {
        dy = -20;
    }
    if (y > SCREEN_HEIGHT) {
        y = -20;
    }
    if (y < -20) {
        y = SCREEN_HEIGHT;
    }
}