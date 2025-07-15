
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

#include <Grid.h>


using namespace std;


struct tile_comp {
    bool operator()(const pair<Tile, int> &a, const pair<Tile, int> &b) {
        return a.second > b.second; // min-heap based on int
    }
};



vector<Tile> get_movement_tiles(Tile start, Grid &grid, int endurance) {
    
    priority_queue<pair<Tile, int>, vector<pair<Tile, int>>, tile_comp> pq;

    Tile curr_tile = start;
    int curr_cost = curr_tile.traverse_cost;
    
    
    pq.push({curr_tile, curr_cost});


    vector<Tile> reachable;

    while(!pq.empty()) {
        
        vector<Tile> adj = grid.get_adjacent(curr_tile);
        vector<Tile> visited;

        for (Tile &t : adj) {
            pq.push({t, (curr_cost + curr_tile.traverse_cost)});
        }

        curr_tile = pq.top().first;
        pq.pop();

        

        if(find(visited.begin(), visited.end(), curr_tile) == visited.end()){
            continue;
        } else if (endurance < (curr_cost + curr_tile.traverse_cost)) {
            continue;
        }

    }




  
    

}


