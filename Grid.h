/**
* @file    grid.h
* @brief   [Short description of what this header provides.]
* @author  Vincent Iadarola
* @date    2025-07-15
**/
#pragma once
using namespace std;



/**********************************************************
**                   Include and Imports                 **
**********************************************************/
//Imports
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

//Includes
#include <Unit.h>
#include <Tile.h>



const extern bool test_gen = true; //testvariable delete later



class Grid {
    public:
        /**********************************************************
        **                     Public Fields                     **
        **********************************************************/
        vector<vector<Tile>> board;


        /**********************************************************
        **              Constructors & Destructors               **
        **********************************************************/
        Grid(int _rows, int _cols);
        virtual ~Grid() = default;

        /**********************************************************
        **                    Public Functions                   **
        **********************************************************/
        vector<Tile> get_adjacent(Tile t);
        vector<Tile> get_row(int r);
        vector<Tile> get_col(int c);
        Tile at(int r, int c);

    private:
        /**********************************************************
        **                     Private Fields                    **
        **********************************************************/
        int rows, cols;
        

        /**********************************************************
        **                    Private Functions                  **
        **********************************************************/
        vector<vector<Tile>> make_default_grid();



};


