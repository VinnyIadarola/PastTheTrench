/**
 * @file    Unit.cpp
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
        Unit(int max_health = 100, int current_health = 100, int endurance_val = 1) {
            maxHP = max_health;
            currHP = current_health;
            endurance = endurance_val;
        }
        virtual ~Unit() = default;


        /**********************************************************
        **                     Public Functions                  **
        **********************************************************/
       //Health
        virtual void update_health(int val) {
            currHP = currHP+val;

            if(currHP > maxHP) {
                currHP = maxHP;
            } else if (currHP <= 0) {
                death();
            }
        }


        //Endurance
        virtual bool can_update_endurance() {
            return endurance > 1;
        }

        virtual void update_endurance(int val) {
            endurance = endurance + val;

            if(endurance > 1) endurance = 1;
            
        }


    private:
        int maxHP;

        
        /**********************************************************
        **                    Private Functions                  **
        **********************************************************/
        virtual void death() {}


        
};