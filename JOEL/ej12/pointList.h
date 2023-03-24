#include <iostream>
#include <vector>

using namespace std;

class pointList
{
    vector<point> vec;

public:
    pointList();
    pointList(const pointList &a);
    pointList &operator=(const pointList &p);

    point centroide();
    void bubbleOrdering();
    void grahamHull();
    point maxEfrompoint(const point &a);

    void addPoint(point a);
    point getPoint(int i);
    vector<point> getVec();

    friend ostream &operator<<(ostream &out, pointList &a);
};