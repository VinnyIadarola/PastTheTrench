/**
* @file    grid.cpp
* @brief   [Short description of what this header provides.]
* @author  Vincent Iadarola
* @date    2025-07-15
**/
#include <Grid.h>







/**********************************************************
**              Constructors & Destructors               **
**********************************************************/
Grid::Grid(int _rows, int _cols) {
    rows = _rows;
    cols = _cols;

    if(test_gen)            
        board = make_default_grid();

}

 Grid::~Grid() = default;



/**********************************************************
**                    Public Functions                   **
**********************************************************/
bool Grid::in_bounds(int row, int col) {
    return (row >= 0) && (row < rows) && (col >= 0) && (col < cols);
}


/** @brief */
vector<Tile> Grid::get_adjacent(Tile t) {
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
            adj.push_back(board[r][c]);
    }

    return adj;
}


/** @brief */
vector<Tile> Grid::get_row(int r) {
    return board[r];
}


/** @brief */
vector<Tile> Grid::get_col(int c) {
    vector<Tile> col;
    col.reserve(cols);

    for(int i = 0; i < rows; i++) {
        col.push_back(board[i][c]);
    }

    return col;
}

/** @brief */
Tile Grid::at(int r, int c) {
    return board[r][c];
}



/**********************************************************
**                    Private Functions                  **
**********************************************************/

vector<vector<Tile>> Grid::make_default_grid(){

    vector<vector<Tile>> grid(rows, vector<Tile>(cols));

    for (vector<Tile>& row : grid)
        for (Tile& t : row)
            t = Tile();

    return grid;
}