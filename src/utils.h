#ifndef UTILS_H
#define UTILS_H

// utils needed for the algorithm

#include <cmath>

class Point {
public:
    int x;
    int y;
    int id;
    Point()
        : x(0), y(0), id(-1) {}
    Point(const int _x, const int _y, const int _id)
        : x(_x), y(_y), id(_id) {}
    bool operator == (const Point& other)
    {
        if (x == other.x && y == other.y) return true;
        return false;
    }
};

inline double min(const double x, const double y) {
    return (x < y) ? x : y;
}

// return the Euclidean distance between two points p1 & p2
inline double dist(const Point& p1, const Point& p2) {
    return std::sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

// compare two points depending on x-axis
// return true if p1 > p2
inline bool cmpX(const Point& p1, const Point& p2) {
    return (p1.x > p2.x) || (p1.x == p2.x && p1.y > p2.y);
}

// compare two points depending on y-axis
// return true if p1 > p2
inline bool cmpY(const Point& p1, const Point& p2) {
    return (p1.y > p2.y) || (p1.y == p2.y && p1.x > p2.x);
}

// sort points[] inside the index-range [lo, hi)
// and store the result into the original array, i.e. points[]
template<class Compare>
void mergeSort(Point* points, const int lo, const int hi, Compare cmp) {
    if (hi - lo < 2) return;
    int mi = (hi + lo) >> 1;
    mergeSort(points, lo, mi, cmp);
    mergeSort(points, mi, hi, cmp);

    int i = lo; int j = mi;
    Point* temp = new Point[hi - lo + 1];
    int cnt = 0;
    while ((i < mi) && (j < hi)) {
        if (cmp(points[i], points[j])) {
            temp[cnt++] = points[j++];
        } else {
            temp[cnt++] = points[i++];
        }
    }
    while (i < mi) temp[cnt++] = points[i++];
    while (j < hi) temp[cnt++] = points[j++];
    for (int k = lo; k < hi; k++) {
        points[k] = temp[k - lo];
    }

    delete [] temp;
}

#endif // UTILS_H
