/**
* @file    Board.h
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



class Board {
    public:
        /**********************************************************
        **                     Public Fields                     **
        **********************************************************/


        /**********************************************************
        **              Constructors & Destructors               **
        **********************************************************/
        Board
    (int _rows, int _cols);
        virtual ~Board
    ();

        /**********************************************************
        **                    Public Functions                   **
        **********************************************************/
        vector<Tile> get_adjacent(Tile t);
        vector<Tile> get_row(int r);
        vector<Tile> get_col(int c);
        Tile at(int r, int c);
        bool in_bounds(int row, int col);

        void set_Board
    (vector<vector<Tile>> &new_grid);


    private:
        /**********************************************************
        **                     Private Fields                    **
        **********************************************************/
        int rows, cols;

        

        /**********************************************************
        **                    Private Functions                  **
        **********************************************************/
        vector<vector<Tile>> make_default_Board
    ();

    protected:
        vector<vector<Tile>> grid; 






};


