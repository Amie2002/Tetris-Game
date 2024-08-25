//
//  block.cpp
//  tetris
//
//  Created by Aditi on 22/08/24.
//

#include "block.hpp"

Block::Block(){
    cellSize=30;
    rotateState=0;
    colors=GetCellColors();
    rowOffset=0;
    colOffset=0;
}

void Block::Draw(int offsetX, int offsetY){
    std::vector<Position> tiles=GetCellPosition();
    for (Position item: tiles) {
        DrawRectangle(item.col*cellSize+offsetX, item.row*cellSize+offsetY, cellSize-1, cellSize-1, colors[id]);
    }
}

void Block::Move(int rows, int cols){
    rowOffset+=rows;
    colOffset+=cols;
}

std::vector<Position> Block::GetCellPosition(){
    std::vector<Position> tiles=cells[rotateState];
    std::vector<Position> movedTiles;
    for (Position item: tiles) {
        Position newPos=Position(item.row+rowOffset, item.col+colOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate(){
    rotateState++;
    if (rotateState==(int)cells.size()) {
        rotateState=0;
    }
}

void Block::UndoRotate(){
    rotateState--;
    if (rotateState==-1) {
        rotateState=(int)cells.size()-1;
    }
}
