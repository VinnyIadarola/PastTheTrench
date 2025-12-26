
#include "tile.hpp"


/******************************************
**                 Public                **
******************************************/
/* Complete Constructor */
Tile::Tile (
    unsigned int cost, 
    Cover cover, 
    bool is_transparent,
    bool is_traversable
) 
    : cost_(cost)
    , cover_(cover)
    , is_transparent_(is_transparent)
    , is_traversable_(is_traversable)
{}


/* Empty Constructor */
Tile::Tile() : Tile(1, Cover::None, true, true) {}



/* destroyAnyObstruction
 *
 * Allows for the destruction of any obsticles during combat i.e. tree exploding or wall falling
*/
Status Tile::destroyAnyObstruction() {
    cover_ = Cover::None;
    is_traversable_ = true;
    is_transparent_ = true;

    return Status::OKAY;
}



/* createObstruction
 *
 * Allows for the creation of an obsticle during combat i.e. sandbag placement or tank emplacement
*/
Status Tile::createObstruction(Cover cover_level) {
    cover_ = cover_level;
    bool open = (cover_ != Cover::High);
    is_transparent_ = open;
    is_traversable_ = open; 

    return Status::OKAY;
}





