#pragma once
#include <Novice.h>
#include <Player.h>
#include "Vector2.h"

void playerMoveSet(Player& player, char keys[]) {
    player.move.x = 0;
    player.move.y = 0;
    if (keys[DIK_W]) {
        player.move.y -= player.speed;
    }
    if (keys[DIK_S]) {
        player.move.y += player.speed;
    }
    if (keys[DIK_A]) {
        player.move.x -= player.speed;
    }
    if (keys[DIK_D]) {
        player.move.x += player.speed;
    }
    player.pos.x += player.move.x;
    player.pos.y += player.move.y;
};

void playerJumpSet(Player& player, char keys[],char preKeys[]) {
    if (player.isJumping == false) {
        if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
            player.gravity = -40.0f;
            player.isJumping = true;
        }
    }

    if (player.isJumping == true) {
        player.gravity += 2.3f;
    }
    player.jumpScrollpos += player.gravity;
    if (player.jumpScrollpos >= 0) {
        player.jumpScrollpos = 0;
        player.isJumping = false;
        player.gravity = 0;
    }
}