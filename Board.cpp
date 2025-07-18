/**
* @file    Board.cpp
* @brief   [Short description of what this header provides.]
* @author  Vincent Iadarola
* @date    2025-07-15
**/
#include <Board.h>







/**********************************************************
**              Constructors & Destructors               **
**********************************************************/
Board::Board(int _rows, int _cols) {
    rows = _rows;
    cols = _cols;

    if(test_gen)            
        grid = make_default_Board();

}

 Board::~Board() = default;



/**********************************************************
**                    Public Functions                   **
**********************************************************/
bool Board::in_bounds(int row, int col) {
    return (row >= 0) && (row < rows) && (col >= 0) && (col < cols);
}


/** @brief */
vector<Tile> Board::get_adjacent(Tile t) {
    if (!in_bounds(t.row, t.col)) throw out_of_range("get_adject: index out of bounds");
    
    static constexpr int DIRS[4][2] = {
        { -1,  0 },   // up
        { +1,  0 },   // down
        {  0, -1 },   // left
        {  0, +1 }    // right
    };

    vector<Tile> adj;
    adj.reserve(4);

    for (auto& d : DIRS) {
        int r = t.row + d[0];
        int c = t.col + d[1];
        if (in_bounds(r, c))
            adj.push_back(grid[r][c]);
    }

    return adj;
}


/** @brief */
vector<Tile> Board::get_row(int r) {
    return grid[r];
}


/** @brief */
vector<Tile> Board::get_col(int c) {
    vector<Tile> col;
    col.reserve(cols);

    for(int i = 0; i < rows; i++) {
        col.push_back(grid[i][c]);
    }

    return col;
}

/** @brief */
Tile Board::at(int r, int c) {
    return grid[r][c];
}


void Board::set_Board(vector<vector<Tile>> &new_grid){
    grid = new_grid;

}



/**********************************************************
**                    Private Functions                  **
**********************************************************/

vector<vector<Tile>> Board::make_default_Board(){

    vector<vector<Tile>> Board(rows, vector<Tile>(cols));

    for (vector<Tile>& row : Board)
        for (Tile& t : row)
            t = Tile();

    return Board;
}