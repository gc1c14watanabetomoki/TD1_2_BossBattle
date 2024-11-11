#pragma once
#include <Novice.h>
#include <Player.h>
#include <Vector2.h>
const char kWindowTitle[] = "";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    // ライブラリの初期化
    Novice::Initialize(kWindowTitle, 1280, 720);

    // キー入力結果を受け取る箱
    char keys[256] = { 0 };
    char preKeys[256] = { 0 };

    Player player;
    player.pos.x = 50;
    player.pos.y = 550;
    player.move.x = 0;
    player.move.y = 0;
    player.speed = 10;
    player.gravity = 0;
    player.direction = 1;
    player.frame = 0;
    player.frameTimer = 0;
    player.isAlive = 1;
    player.HP = 100;
    player.isJumping = 0;
    player.jumpScrollpos = 0;
    player.size = 128;
    player.radius = player.size / 2;


    int playerGraph = Novice::LoadTexture("./Resources/player128x128.png");
    int backGroundGraph = Novice::LoadTexture("./Resources/Sprite-0002.png");


    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0) {
        // フレームの開始
        Novice::BeginFrame();

        // キー入力を受け取る
        memcpy(preKeys, keys, 256);
        Novice::GetHitKeyStateAll(keys);

        ///
        /// ↓更新処理ここから
        ///
        
        playerMoveSet(player, keys);
        playerJumpSet(player, keys, preKeys);


        if (keys[DIK_A]) {
            player.direction = -1;
        }
        if (keys[DIK_D]) {
            player.direction = 1;
        }
        /// ↑更新処理ここまで
        ///

        ///
        /// ↓描画処理ここから
        ///
        
        Novice::DrawSprite(0, 0, backGroundGraph, 1.0f, 1.0f, 0.0f, WHITE);

        Novice::DrawBox((int)player.pos.x - (int)player.radius, (int)player.pos.y - (int)player.radius, (int)player.size, (int)player.size, 0, WHITE, kFillModeSolid);
        
        Novice::DrawQuad(
            (int)player.pos.x - ((int)player.radius * player.direction), (int)player.pos.y - (int)player.radius + (int)player.jumpScrollpos,
            (int)player.pos.x + ((int)player.radius * player.direction), (int)player.pos.y - (int)player.radius + (int)player.jumpScrollpos,
            (int)player.pos.x - ((int)player.radius * player.direction), (int)player.pos.y + (int)player.radius + (int)player.jumpScrollpos,
            (int)player.pos.x + ((int)player.radius * player.direction), (int)player.pos.y + (int)player.radius + (int)player.jumpScrollpos,
            0, 0, (int)player.size, (int)player.size, playerGraph, WHITE);

        Novice::ScreenPrintf(10, 10, "player.jumpScrollpos : %f", player.jumpScrollpos);
        Novice::ScreenPrintf(10, 30, "player.gravity : %f", player.gravity);

        ///
        /// ↑描画処理ここまで
        ///

        // フレームの終了
        Novice::EndFrame();

        // ESCキーが押されたらループを抜ける
        if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
            break;
        }
    }
    // ライブラリの終了
    Novice::Finalize();
    return 0;
}
