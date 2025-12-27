#include "unit.hpp"


using std::priority_queue;
using std::unordered_map;
using std::list;

/******************************************************
***                   Constructors                  ***
******************************************************/
/* Full constructor 
 *
 * Should be used for actual character implementation
*/
Unit::Unit(
    std::string name, 
    unsigned int max_health,
    unsigned int init_dmg,
    unsigned int base_stamina,
    unsigned int base_eye_sight,
    bool is_ally,
    Coordinate pos,
    Dim dim
) :
    name_(std::move(name)),
    max_health_(max_health),
    health_( max_health - init_dmg),
    base_stamina_(base_stamina),
    base_eye_sight_(base_eye_sight),
    is_ally_(is_ally),
    pos_(pos),
    dim_(dim)    
{}


/* Derived class constrctur
 *
 * Uses the UnitTraits for readibility in derived classes
*/
Unit::Unit(UnitTraits unit_traits) 
    : Unit(
        std::move(unit_traits.name),
        unit_traits.max_health,
        unit_traits.init_dmg,
        unit_traits.base_stamina,
        unit_traits.base_eye_sight,
        unit_traits.is_ally,
        unit_traits.pos,
        unit_traits.dim
    )
{}


/* Testing Constructor
 *
 * For spawning dummy units
*/
Unit::Unit(bool is_ally, Coordinate pos) 
    : Unit(
        "dud",
        1,
        0,
        1,
        1,
        is_ally,
        pos,
        Dim(1, 1)
    )
{}



/******************************************************
***                    Functions                    ***
******************************************************/
/* Find valid Movement paths
 *
 * A modified dykstras algorithm that uses tile cost 
 * and accounts for dimension of object. 
*/
Status Unit::updateValidMoves(GridSpace &board) {


    moves_.clear();

    priority_queue<QueueElement> pq;
    
    
    pq.emplace(QueueElement(pos_, Coordinate(-1, -1), 0));

    
    while(!pq.empty()) {
        QueueElement head = pq.top();
        moves_.emplace(head.curr_pos, head.prev_pos);
        pq.pop();

        getValidNeighbors(board, head, pq);


        // Should iterate till the lowest cost node isnt already seen
        while(
            head = pq.top(),
            moves_.find(head.curr_pos) != moves_.end()
        ) pq.pop();
    }
    

    return Status::OKAY;
}


/* Private helper for updateValidMoves
 *
 * Checks that the neighbors are moveable and the dimension fits
*/
Status inline Unit::getValidNeighbors(GridSpace &board, QueueElement &element, priority_queue<QueueElement> &pq) {
    constexpr int unit_vectors[4][2] = {
        { 0,  1},   // +y
        { 0, -1},   // -y
        { 1,  0},   // +x
        {-1,  0}    // -x
    };

    auto &[x, y] = element.curr_pos;

    for (const auto [x_dir, y_dir] : unit_vectors) {
        int total_cost = 0;

        bool rectangle_traversable = checkRectangle(board, total_cost, x_dir, y_dir, x, y);
        if (!rectangle_traversable) 
            continue; 

        
        int new_x = x + x_dir;
        int new_y = y + y_dir;
        int new_cost = std::ceil(static_cast<double>(total_cost) / (dim_.width * dim_.length));

        pq.emplace(QueueElement(Coordinate(new_x, new_y), element.curr_pos, new_cost));
    }

    return Status::OKAY;

}

bool inline Unit::checkRectangle(GridSpace &board, int &total_cost, const int x, const int y, const int x_dir, const int y_dir) {
    for (int w = 0; w != dim_.width; ++w) {
        for (int l = 0; l != dim_.length; ++l) {
            
            int tx = x + x_dir + w * (-y_dir) - l * x_dir;
            int ty = y + y_dir + w * ( x_dir) - l * y_dir;


    

            Tile &curr_tile = board[tx][ty];
            
            if (!curr_tile.isTraversable()) 
                return false;


            total_cost += curr_tile.getTraversalCost();
        }
    }
    return true;
}


const unordered_map<Coordinate, Coordinate>& Unit::getValidMoves() const {
    return moves_;
}

const list<Unit::Opponents>& Unit::getValidTargets() const {
    return visibile_opponents_;
}   