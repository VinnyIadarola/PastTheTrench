#include "soldier.hpp"



Status Soldier::determineState() {
    // Still healthy
    if(health_ > (max_health_ * injury_ratio)) 
        return Status::OKAY;

    // Already down
    if(state_ == UnitState::Down) {
        state_ = (--down_count_) ?  UnitState::Down : UnitState::Dead;
        return Status::OKAY;
    }

    // Going down
    if(health_ <= 0) {
        state_ = UnitState::Down;     
        int extra_count_range = down_count_max - down_count_min;
        
        //TODO whenever we init the game do srand(time(0))
        down_count_ = rand() % (extra_count_range + 1);
        return Status::OKAY;
    }


    // In Injury range
    bool induce_injury = (rand() % (101)) < injury_chance;
    state_ = (induce_injury) ? UnitState::Injured : state_; 

    return Status::OKAY;
}