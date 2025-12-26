#pragma once

#include <cstddef>
#include <functional>


enum class Status {
    OKAY,
    ERROR
};


struct Coordinate {
    int x = 0;
    int y = 0;

    Coordinate(int x_, int y_) : x(x_), y(y_) {}

    bool operator == (const Coordinate &other) const {
        return (x == other.x) && (y == other.y);
    }
};

// i have no clue
namespace std {
    template <>
    struct hash<Coordinate> {
        size_t operator () (const Coordinate& coord) const {
            size_t h1 = std::hash<int>{}(coord.x);
            size_t h2 = std::hash<int>{}(coord.y);
            return h1 ^ (h2 << 1);
        }
    };
}


struct Dim {
    unsigned int width;
    unsigned int length;

    Dim(unsigned int w, unsigned int l) : width(w), length(l) {}
};


enum class Cover {
    High,
    Medium,
    Low,
    None
};


enum class UnitState {
    Healthy,
    Injured,
    Down,
    Dead
};
