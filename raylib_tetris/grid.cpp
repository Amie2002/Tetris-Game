//
//  grid.cpp
//  tetris
//
//  Created by Aditi on 21/08/24.
//

#include "grid.hpp"
#include <iostream>
#include "colors.hpp"

Grid::Grid(){
    ROWS=20;
    COLS=10;
    cellSize=30;
    Initialize();
    colors=GetCellColors();
}

void Grid::Initialize(){
    for (int row=0; row<ROWS; row++) {
        for (int col=0; col<COLS; col++) {
            grid[row][col]=0;
        }
    }
}

void Grid::Draw(){
    for (int row=0; row<ROWS; row++) {
        for (int col=0; col<COLS; col++) {
            int cellValue=grid[row][col];
            DrawRectangle(col*cellSize+11, row*cellSize+11, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }
}

bool Grid::isCellOutside(int row, int col){
    if (row>=0 && row<ROWS && col>=0 && col<COLS) {
        return false;
    }
    return true;
}

bool Grid::isCellEmpty(int row, int col){
    if (grid[row][col] == 0) {
        return true;
    }
    return false;
}

int Grid::ClearFullRows(){
    int comp=0;
    for (int row=ROWS-1; row>=0; row--) {
        if (isRowFull(row)) {
            ClearRow(row);
            comp++;
        }
        else if (comp>0){
            MoveRowDown(row, comp);
        }
    }
    return comp;
}

bool Grid::isRowFull(int row){
    for (int col=0; col<COLS; col++) {
        if (grid[row][col]==0) {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row){
    for (int col=0; col<COLS; col++) {
        grid[row][col]=0;
    }
}

void Grid::MoveRowDown(int row, int ROWS){
    for (int col=0; col<COLS; col++) {
        grid[row+ROWS][col]=grid[row][col];
        grid[row][col]=0;
    }
}
