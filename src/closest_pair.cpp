#include "closest_pair.h"
#include <float.h>
#include <iostream>

std::pair<int, int> bruteForce(const Point* points, const int n) {
    double min_dist = DBL_MAX;
    std::pair<int, int> res(-1, -1);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dist(points[i], points[j]) < min_dist) {
                min_dist = dist(points[i], points[j]);
                res.first = points[i].id;
                res.second = points[j].id;
            }
        }
    }
    return res;
}

std::pair<int, int> fastClosestPair(const Point* points, const int n) {
    Point* points_x = new Point[n];
    Point* points_y = new Point[n];
    for (int i = 0; i < n; i++) {
        points_x[i] = points[i];
        points_y[i] = points[i];
    }

    mergeSort(points_x, 0, n, cmpX);
    mergeSort(points_y, 0, n, cmpY);

    // check if any two of them are the same point.
    // If so, the minimum distance must be 0.
    for (int i = 0; i < n-1; i++)
    {
        if (points_x[i] == points_x[i+1])
        {
            std::pair<int, int> res(points_x[i].id, points_x[i+1].id);
            return res;
        }
    }

    std::pair<int, int> res = closest(points, points_x, points_y, n);
    delete [] points_x;
    delete [] points_y;
    return res;
}

std::pair<int, int> closest(const Point* points, Point* points_x, Point* points_y, const int n) {
    if (n <= 3) return bruteForce(points_x, n);

    int mi = n >> 1;
    Point mid_point = points_x[mi];

    Point points_left[mi];
    Point points_right[n-mi];

    int left = 0; int right = 0;
    for (int i = 0; i < n; i++) {
        if (cmpX(mid_point, points_y[i])) {
            points_left[left++] = points_y[i];
        } else {
            points_right[right++] = points_y[i];
        }
    }
    // std::cout << "points_left\n";
    // for (int i = 0; i < mi; i++) {
    //     std::cout << points_left[i].x << ", " << points_left[i].y << '\n';
    // }
    // std::cout << "points_right\n";
    // for (int i = 0; i < n-mi; i++) {
    //     std::cout << points_right[i].x << ", " << points_right[i].y << '\n';
    // }

    std::pair<int, int> left_pair = closest(points, points_x, points_left, mi);
    std::pair<int, int> right_pair = closest(points, points_x + mi, points_right, n - mi);

    bool left_valid = true; bool right_valid = true;
    if (left_pair.first == -1 || left_pair.second == -1)
    {
        left_valid = false;
    }
    if (right_pair.first == -1 || right_pair.second == -1)
    {
        right_valid = false;
    }

    double d1 = DBL_MAX;
    double d2 = DBL_MAX;
    if (left_valid) {
        d1 = dist(points[left_pair.first], points[left_pair.second]);
    }
    if (right_valid) {
    d2 = dist(points[right_pair.first], points[right_pair.second]);
    }

    std::pair<int, int> res(-1, -1);
    if (left_valid)
    {
        res = left_pair;
    }

    double d = d1;
    if (d2 < d)
    {
        d = d2;
        res = right_pair;
    }

    Point points_middle[n];
    int mid_num = 0;
    for (int i = 0; i < n; i++) {
        if (std::abs(points_y[i].x - mid_point.x) < d) {
            points_middle[mid_num++] = points_y[i];
        }
    }

    std::pair<int, int> strip_res = stripClosest(points_middle, mid_num, d);
    if (strip_res.first == -1 || strip_res.second == -1) {
        return res;
    } else {
        return strip_res;
    }
}

std::pair<int, int> stripClosest(const Point* points_middle, const int mid_num, const double d) {

    double min = d;
    std::pair<int, int> res(-1, -1);
    for (int i = 0; i < mid_num; i++) {
        for (int j = i+1; j < mid_num; j++) {
            if (points_middle[j].y - points_middle[i].y >= min) continue;
            if (dist(points_middle[j], points_middle[i]) < min) {
                min = dist(points_middle[j], points_middle[i]);
                res.first = points_middle[i].id;
                res.second = points_middle[j].id;
            }
        }
    }
    return res;
}
