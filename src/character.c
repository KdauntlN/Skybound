#define _USE_MATH_DEFINES
#include <math.h>
#include "character.h"
#include "raylib.h"
#include "constants.h"

float x = SCREEN_WIDTH / 2;
float y = SCREEN_HEIGHT / 2;
double dx = 0;
double dy = 0;
float speed = 0.2;
float gravity = 0.1;
float rotation = 90;
void drawCharacter(int width, int height, Color playerColour) {
    Rectangle rect = {x, y, width, height};
    DrawRectanglePro(rect, (Vector2){10, 10}, rotation, playerColour);
    dy += gravity;
    y += dy;
    x += dx;
    if (dx != 0) {
        dx *= 0.99;
    }
    if (dy != 0) {
        dy *= 0.99;
    }
    if (IsKeyDown(KEY_W)) {
        dy -= sinf(rotation * (M_PI / 180.0f)) * speed;
        dx += cosf(rotation * (M_PI / 180.0f)) * -speed;
    }
    if (IsKeyDown(KEY_A)) {
        rotation -= 5;
    }
    if (IsKeyDown(KEY_D)) {
        rotation += 5;
    }
    if (rotation > 360) {
        rotation -= 360;
    }
    if (rotation < 0) {
        rotation += 360;
    }
    if (dy > 5) {
        dy = 5;
    }
    if (dy < -5) {
        dy = -5;
    }
    if (dx > 5) {
        dx = 5;
    }
    if (dx < -5) {
        dx = -5;
    }
    if (y > SCREEN_HEIGHT + 20) {
        y = -20;
    }
    if (y < -20) {
        y = SCREEN_HEIGHT + 20;
    }
    if (x + 25 < 0) {
        x = SCREEN_WIDTH + 20;
    }
    if (x > SCREEN_WIDTH + 20) {
        x = -25;
    }
}