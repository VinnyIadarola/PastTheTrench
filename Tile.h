/**
* @file    Tile.h
* @brief   [Short description of what this header provides.]
* @author  Vincent Iadarola
* @date    2025-07-15
**/
#pragma once

using namespace std;


/**********************************************************
**                   Include and Imports                 **
**********************************************************/
#include <utility>

#include <Unit.h>




/**********************************************************
**                    Helper Structures                  **
**********************************************************/
enum class TileType {
    GROUND
};

struct Cover {
    bool north;
    bool east;
    bool south;
    bool west;

    Cover(bool n = false, bool e = false, bool s = false, bool w = false) : north(n), east(e), south(s), west(w) {}
};



/**********************************************************
**                        Classes                        **
**********************************************************/
class Tile {
    public:
        /**********************************************************
        **                     Public Fields                     **
        **********************************************************/
        TileType type;
        Cover cover;

        Unit* occupied_by;
        int traverse_cost;

        int row;
        int col;

        /**********************************************************
        **              Constructors & Destructors               **
        **********************************************************/
        Tile(TileType _type = TileType::GROUND, 
            Cover _cover = {}, 
            int _traverse_cost = 1, 
            Unit* _occupied_by = nullptr,
            int _row = 0,
            int _col = 0
        );
        virtual ~Tile();



};


