/**
* @file    Tile.cpp
* @brief   [Short description of what this header provides.]
* @author  Vincent Iadarola
* @date    2025-07-15
**/




/**********************************************************
**                   Include and Imports                 **
**********************************************************/
#include <Tile.h> 
   





/**********************************************************
**              Constructors & Destructors               **
**********************************************************/
Tile::Tile(TileType _type = TileType::GROUND, 
    Cover _cover = {}, 
    int _traverse_cost = 1, 
    Unit* _occupied_by = nullptr,
    int _row = 0,
    int _col = 0
) {
    type = _type;
    cover = _cover;
    traverse_cost = _traverse_cost;
    occupied_by = _occupied_by;
    row = _row;
    col = _col;
};

        virtual ~Tile() = default;

