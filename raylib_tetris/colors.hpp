//
//  colors.hpp
//  tetris
//
//  Created by Aditi on 22/08/24.
//
#pragma once

#ifndef colors_hpp
#define colors_hpp

#include <stdio.h>
#include <raylib.h>
#include <vector>

extern const Color darkGrey;
extern const Color darkblue;
extern const Color cyan;
extern const Color lightBlue;
std::vector<Color> GetCellColors();

#endif /* colors_hpp */
