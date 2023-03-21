#ifndef CLOSEST_PAIR_H
#define CLOSEST_PAIR_H

// algorithms for computing closest pairs
#include "utils.h"
#include <utility>

std::pair<int, int> bruteForce(const Point* points, const int n);

std::pair<int, int> fastClosestPair(const Point* points, const int n);

std::pair<int, int> closest(const Point* points, Point* points_x, Point* points_y, const int n);

std::pair<int, int> stripClosest(const Point* points_middle, const int mid_num, const double d);

#endif // CLOSEST_PAIR_H
