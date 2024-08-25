//
//  block.hpp
//  tetris
//
//  Created by Aditi on 22/08/24.
//
#pragma  once

#ifndef block_hpp
#define block_hpp

#include <stdio.h>
#include <map>
#include <vector>
#include "position.hpp"
#include "colors.hpp"

class Block {
    
public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int cols);
    std::vector<Position> GetCellPosition();
    void Rotate();
    void UndoRotate();
    int id;
    std::map<int, std::vector<Position>> cells;
    
private:
    int cellSize;
    int rotateState;
    std::vector<Color> colors;
    int rowOffset;
    int colOffset;
};

#endif /* block_hpp */
