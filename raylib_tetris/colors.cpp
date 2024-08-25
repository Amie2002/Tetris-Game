//
//  colors.cpp
//  tetris
//
//  Created by Aditi on 22/08/24.
//

#include "colors.hpp"

const Color darkGrey={26,31,40,255};
const Color darkblue={44, 44, 127, 255};
const Color cyan={21, 204, 209, 255};
const Color lightBlue={59, 85, 162, 255};

std::vector<Color> GetCellColors(){
    return {darkGrey,GREEN,RED,ORANGE,YELLOW,PURPLE,cyan,DARKBLUE};
}
