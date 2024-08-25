//
//  gameupdate.cpp
//  tetris
//
//  Created by Aditi on 23/08/24.
//

#include "gameupdate.hpp"
#include <random>

GameUpdate::GameUpdate(){
    grid=Grid();
    blocks=GetAllBlocks();
    currentBlock=GetRandomBlock();
    nextBlock=GetRandomBlock();
    gameOver = false;
    score=0;
    InitAudioDevice();
    std::string musicfilepath="/Users/aditi/Documents/my-c++_codes/Raylib_tetris/raylib_tetris/assets/game-music-loop-7-145285.mp3";
    std::string rotatefilepath="/Users/aditi/Documents/my-c++_codes/Raylib_tetris/raylib_tetris/assets/blip-131856.mp3";
    std::string clearfilepath="/Users/aditi/Documents/my-c++_codes/Raylib_tetris/raylib_tetris/assets/game-start-6104.mp3";
    music=LoadMusicStream(musicfilepath.c_str());
    PlayMusicStream(music);
    rotateSound = LoadSound(rotatefilepath.c_str());
    clearSound = LoadSound(clearfilepath.c_str());
}

GameUpdate::~GameUpdate(){
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}

Block GameUpdate::GetRandomBlock(){
    if (blocks.empty()) {
        blocks=GetAllBlocks();
    }
    int randomIndex = rand()%blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> GameUpdate::GetAllBlocks(){
    return {IBlock(),JBlock(),LBlock(),OBlock(),SBlock(),TBlock(),ZBlock()};
}

void GameUpdate::Draw(){
    grid.Draw();
    currentBlock.Draw(11,11);
    switch (nextBlock.id)
        {
        case 3:
            nextBlock.Draw(255, 290);
            break;
        case 4:
            nextBlock.Draw(255, 280);
            break;
        default:
            nextBlock.Draw(270, 270);
            break;
        }
}

void GameUpdate::HandleInput(){
    int keyPressed=GetKeyPressed();
    if (gameOver && keyPressed== KEY_ENTER) {
        gameOver=false;
        GameReset();
    }
    switch (keyPressed) {
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlockDown();
            UpdateScore(0, 1);
            break;
        case KEY_UP:
            RotateBlock();
            break;
    }
}

void GameUpdate::MoveBlockLeft(){
    if (!gameOver) {
        currentBlock.Move(0, -1);
        if (isBlockOutside() || BlockFits()==false) {
            currentBlock.Move(0, 1);
        }
    }
}

void GameUpdate::MoveBlockRight(){
    if (!gameOver) {
        currentBlock.Move(0, 1);
        if (isBlockOutside() || BlockFits()==false) {
            currentBlock.Move(0, -1);
        }
    }
}

void GameUpdate::MoveBlockDown(){
    if (!gameOver) {
        currentBlock.Move(1, 0);
        if (isBlockOutside() || BlockFits()==false) {
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }
}

void GameUpdate::RotateBlock(){
    if (!gameOver) {
        currentBlock.Rotate();
        if (isBlockOutside() || BlockFits()==false) {
            currentBlock.UndoRotate();
        }
        else{
            PlaySound(rotateSound);
        }
    }
}

bool GameUpdate::isBlockOutside(){
    std::vector<Position> tiles = currentBlock.GetCellPosition();
    for (Position item: tiles) {
        if (grid.isCellOutside(item.row, item.col)) {
            return true;
        }
    }
    return false;
}

void GameUpdate::LockBlock(){
    std::vector<Position> tiles= currentBlock.GetCellPosition();
    for (Position item: tiles) {
        grid.grid[item.row][item.col] = currentBlock.id;
    }
    currentBlock=nextBlock;
    if (BlockFits()==false) {
        gameOver=true;
    }
    nextBlock= GetRandomBlock();
    int rowsCleared=grid.ClearFullRows();
    if (rowsCleared>0) {
        PlaySound(clearSound);
        UpdateScore(rowsCleared, 0);
    }
}

bool GameUpdate::BlockFits(){
    std::vector<Position> tiles=currentBlock.GetCellPosition();
    for (Position item: tiles) {
        if (grid.isCellEmpty(item.row, item.col)==false) {
            return false;
        }
    }
    return  true;
}

void GameUpdate::GameReset(){
    grid.Initialize();
    blocks=GetAllBlocks();
    currentBlock=GetRandomBlock();
    nextBlock=GetRandomBlock();
    score=0;
}

void GameUpdate::UpdateScore(int linesCleared, int moveDownPoints){
    switch (linesCleared) {
        case 1:
            score+=100;
            break;
        case 2:
            score+=300;
            break;
        case 3:
            score+=500;
            break;
        default:
            break;
    }
    score+=moveDownPoints;
}
