#pragma once

#include "general.hpp"



class Tile {
    friend class Board;



protected:
    int cost_ = 1; 
    Cover cover_ = Cover::None;
    bool is_transparent_ = true;
    bool is_traversable_ = true;
    


public:

    /* Complete Constructor */
    Tile(unsigned int cost, Cover cover, bool is_transparent, bool is_traversable);


    /* Empty Constructor */
    Tile();


    virtual ~Tile() = default;


    /* destroyAnyObstruction
     *
     * Allows for the destruction of any obsticles during combat i.e. tree exploding or wall falling
    */
    virtual Status destroyAnyObstruction();


    /* createObstruction
     *
     * Allows for the creation of an obsticle during combat i.e. sandbag placement or tank emplacement
    */
    virtual Status createObstruction(Cover cover_level);

    /* getTraversalCost
     *
     * getter for cost
    */
    virtual unsigned int getTraversalCost() const noexcept;

    virtual bool isTraversable() const noexcept;


    


};