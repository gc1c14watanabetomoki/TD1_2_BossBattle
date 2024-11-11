#pragma once
#include <Novice.h>
#include "Vector2.h"
typedef struct Player {
    Vector2 pos;
    Vector2 move;
    float size;
    float radius;
    float speed;
    float gravity;
    float acceleration;
    float jumpTime;
    bool isJumping;
    bool isAlive;
    float aliveTimer;
    float jumpScrollpos;
    int direction;
    float stunTime;
    int frame;
    int frameTimer;
    int HP;
} Player;

void playerMoveSet(Player& player, char keys[]);