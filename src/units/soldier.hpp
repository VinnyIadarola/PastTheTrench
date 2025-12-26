#pragma once

#include "../framework/general.hpp"
#include "unit.hpp"
#include <vector>
#include "../items/weapon.hpp"
#include "../items/item.hpp"


class Soldier : public Unit {
    public:

        Soldier(
            UnitTraits unit_traits,

            // Soldier specific
            Weapon* held_weapon,
            std::vector<Item*> backpack
        ) : 
            Unit (unit_traits), 
            held_weapon_(held_weapon), 
            backpack_(backpack) 
        {}

        virtual Status updateValidMoves() override;
        virtual Status updateAccuracies() override;




    protected:
    

        
        // items i think i want to move up
        Weapon* held_weapon_;
        std::vector<Item*> backpack_;


        virtual Status determineState() override;





};


