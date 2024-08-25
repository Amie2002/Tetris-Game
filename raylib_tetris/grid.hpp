//
//  grid.hpp
//  tetris
//
//  Created by Aditi on 21/08/24.
//
#pragma once
#include <vector>
#include <raylib.h>

#ifndef grid_hpp
#define grid_hpp


#include <stdio.h>

class Grid {
    
public:
    Grid();
    void Initialize();
    void Draw();
    bool isCellOutside(int row, int col);
    bool isCellEmpty(int row, int col);
    int ClearFullRows();
    int grid[20][10];
    
private:
    bool isRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int ROWS);
    int ROWS;
    int COLS;
    int cellSize;
    std::vector<Color> colors;
};

#endif /* grid_hpp */
