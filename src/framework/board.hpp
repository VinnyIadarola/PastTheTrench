#pragma once

#include <vector>
#include "tile.hpp"
#include "general.hpp"


using GridSpace = std::vector<std::vector<Tile>>; 

class Board {

    private:
        
        GridSpace board_;
    //     std::vector<Unit*> units_;

    


        

    public:

        Board();
        // could be vector if ensure no changes mid combat
        Status updateMoves(bool for_friendlies);





};