/**
 * @file    Unit.cpp
 * @brief   [Short description of what this header provides.]
 * @author  Vincent Iadarola
 * @date    2025-07-15
 */

#include <Unit.h>



/**********************************************************
**              Constructors & Destructors               **
**********************************************************/
Unit::Unit(int max_health, int current_health, int endurance_val) {
    maxHP = max_health;
    currHP = current_health;
    endurance = endurance_val;
}



/**********************************************************
**                     Public Functions                  **
**********************************************************/
//Health
int Unit::update_health(int val) {
    currHP = currHP+val;

    if(currHP > maxHP) {
        currHP = maxHP;
    } else if (currHP <= 0) {
        currHP = 0;
        //death()
    }
    return currHP;
}




int Unit::update_endurance(int val) {
    endurance = endurance + val;

    if(endurance < 1) endurance = 1;
    
    return endurance;
}



/**********************************************************
**                    Private Functions                  **
**********************************************************/
string Unit::death() {
    return "death";
}

bool Unit::can_update_endurance() {
    return endurance > 1; //basicalyl useless but meant to be overriden 
}




