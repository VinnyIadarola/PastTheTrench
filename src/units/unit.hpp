#pragma once

#include <queue>
#include <string>
#include "../framework/general.hpp"
#include <list>
#include "../framework/board.hpp"
#include <unordered_map>


class Unit {
    public:
        /******************************************************
        ***                 Helper Structs                  ***
        ******************************************************/
        struct Opponents {
            const std::reference_wrapper<const Unit> target;
            bool is_shootable;
            double distance; //tiles wise
        };


        struct UnitTraits {
            std::string name; 
            unsigned int max_health;
            unsigned int init_dmg;
            unsigned int base_stamina;
            unsigned int base_eye_sight;
            bool is_ally;
            Coordinate pos;
            Dim dim;
        };


        /******************************************************
        ***                   Constructors                  ***
        ******************************************************/
        Unit(
            std::string name, 
            unsigned int max_health,
            unsigned int init_dmg,
            unsigned int base_stamina,
            unsigned int base_eye_sight,
            bool is_ally,
            Coordinate pos,
            Dim dim
        );

        Unit(UnitTraits unit_traits);
        Unit(bool is_ally, Coordinate pos);
     

        

        /******************************************************
        ***                    Functions                    ***
        ******************************************************/
        Status updateValidMoves(GridSpace &board);
        virtual Status updateVisibleOpponents(std::list<Unit*> activeUnits) = 0;

        std::unordered_map<Coordinate, Coordinate>& getValidMoves() const;
        std::list<Opponents>& getValidTargets() const;

        Status moveTiles(Coordinate &dest);





    protected:
        /******************************************************
        ***                  Helper Structs                 ***
        ******************************************************/
        struct QueueElement {
            Coordinate curr_pos;
            Coordinate prev_pos;

            int cost;

            bool operator < (const QueueElement& other) const {
                return cost < other.cost;
            }

            QueueElement(Coordinate c, Coordinate p, int s) : curr_pos(c), prev_pos(p), cost(s) {};
        };
            

        /******************************************************
        ***                Constant Trait values            ***
        ******************************************************/
        static constexpr int accuracy_penalty = 5; 
        static constexpr int down_count_min = 3;
        static constexpr int down_count_max = 6;
        static constexpr double injury_ratio = 1.0/4.0;
        static constexpr int injury_chance = 4; 



        /******************************************************
        ***                     Traits                      ***
        ******************************************************/
        // Internal
        std::string name_;
        int health_;
        int max_health_;
        int stamina_, base_stamina_; 
        int eye_sight_, base_eye_sight_;

        int down_count_;

        // States
        bool is_ally_;
        UnitState state_;

        // positional details
        Coordinate pos_; //centered around 
        Dim dim_;
        std::unordered_map<Coordinate, Coordinate> moves_;
        std::list<Opponents> visibile_opponents_;
        


        /******************************************************
        ***                     Functions                   ***
        ******************************************************/
        virtual Status determineState() = 0;
        virtual Status inline getValidNeighbors(GridSpace &board, QueueElement &element, std::priority_queue<QueueElement> &pq) = 0;





        private:
            bool inline checkRectangle(GridSpace &board, int &total_cost, const int x, const int y, const int x_dir, const int y_dir);

};


