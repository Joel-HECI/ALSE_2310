#include <iostream>
#include <vector>
// #include "punto2d.h"

using namespace std;

class pointList
{
    vector<point> vec;

public:
    pointList();
    pointList(const pointList &a);
    pointList &operator=(const pointList &p);

    point centroide();
    vector<point> bubbleOrdering();
    vector<point> grahamHull();

    void addPoint(point a);
    point getPoint(int i);
    vector<point> getVec();

    friend ostream &operator<<(ostream &out, pointList &a);
};