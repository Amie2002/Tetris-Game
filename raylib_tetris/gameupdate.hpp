//
//  gameupdate.hpp
//  tetris
//
//  Created by Aditi on 23/08/24.
//

#pragma once
#ifndef gameupdate_hpp
#define gameupdate_hpp

#include <stdio.h>
#include "grid.hpp"
#include "blocks.cpp"

class GameUpdate {
    
public:
    GameUpdate();
    ~GameUpdate();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool gameOver;
    int score;
    Music music;
    
private:
    void MoveBlockLeft();
    void MoveBlockRight();
    void RotateBlock();
    bool isBlockOutside();
    void LockBlock();
    bool BlockFits();
    void GameReset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    Grid grid;
    std::vector<Block> blocks;
    Block GetRandomBlock();
    std::vector<Block> GetAllBlocks();
    Block currentBlock;
    Block nextBlock;
    Sound rotateSound;
    Sound clearSound;
};

#endif /* gameupdate_hpp */
