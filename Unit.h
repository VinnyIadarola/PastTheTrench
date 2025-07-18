#pragma once

/**
 * @file    Unit.h
 * @brief   [Short description of what this header provides.]
 * @author  Vincent Iadarola
 * @date    2025-07-15
 */

/**********************************************************
**                  Imports and Includes                 **
**********************************************************/
#include <string>
using namespace std;

class Unit {
    public:
        /**********************************************************
        **                     Public Fields                     **
        **********************************************************/
        int currHP;
        int endurance;

        /**********************************************************
        **              Constructors & Destructors               **
        **********************************************************/
        Unit(int max_health = 100, int current_health = 100, int endurance_val = 100);
        virtual ~Unit() = default;


        /**********************************************************
        **                     Public Functions                  **
        **********************************************************/
        // Health
        virtual int update_health(int val);

        //Endurance
        virtual int update_endurance(int val);




    private:
        /**********************************************************
        **                     Private Fields                    **
        **********************************************************/
        int maxHP;

        /**********************************************************
        **                    Private Functions                  **
        **********************************************************/
        virtual string death();
        virtual bool can_update_endurance();


};

