#pragma once

/**
 * @file    Unit.h
 * @brief   [Short description of what this header provides.]
 * @author  Vincent Iadarola
 * @date    2025-07-15
 */

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
        Unit(int max_health, int current_health, int endurance_val);
        virtual ~Unit();


        /**********************************************************
        **                     Public Functions                  **
        **********************************************************/
        // Health
        virtual void update_health(int val);

        //Endurance
        virtual bool can_update_endurance();
        virtual void update_endurance(int val);




    private:
        /**********************************************************
        **                     Private Fields                    **
        **********************************************************/
        int maxHP;

        /**********************************************************
        **                    Private Functions                  **
        **********************************************************/
        virtual void death();

};

