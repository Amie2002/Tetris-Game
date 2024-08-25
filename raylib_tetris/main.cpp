//
//  main.cpp
//  RaylibExample
//
//  Created by Aditi on 06/08/24.
//

// main.cpp

#include <raylib.h>
#include "colors.hpp"
#include "gameupdate.hpp"
#include <iostream>

double lastUpdateTime=0;

bool EventTriggered(double interval){
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main() {
    // Initialize the window
    InitWindow(500, 620, "Raylib :: Tetris");

    // Set the target frame rate
    SetTargetFPS(60);
    
    GameUpdate game=GameUpdate();

    // Main game loop
    while (!WindowShouldClose()) {
        //actions taken
        UpdateMusicStream(game.music);
        game.HandleInput();
        
        //action for blocks falling
        if (EventTriggered(0.2)) {
            game.MoveBlockDown();
        }
        
        // Draw a red square
        BeginDrawing();
        
        //background color
        ClearBackground(darkblue);
        DrawText("Score", 360, 15, 36, LIGHTGRAY);
        DrawText("Next", 370, 175, 36, LIGHTGRAY);
        if (game.gameOver) {
            DrawText("GAME OVER", 323, 453, 29, BLACK);
            DrawText("GAME OVER", 320, 450, 29, RED);
            DrawText("press ENTER\n  to restart", 333, 480, 22, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
        
        char scoreText[10];
        snprintf(scoreText, sizeof(scoreText), "%d", game.score);
        Vector2 textSize = {(float)MeasureText(scoreText, 36),36};
        
        DrawText(scoreText, 320+(170-textSize.x)/2, 67, 36, LIGHTGRAY);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        
        game.Draw();
        
        EndDrawing();
    }

    // De-initialize the window
    CloseWindow();

    return 0;
}
