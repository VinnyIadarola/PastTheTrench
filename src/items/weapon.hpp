#pragma once
#include "item.hpp"

class Weapon : Item {
    public:
        unsigned int damage = 4;
        bool is_melee = true;
};