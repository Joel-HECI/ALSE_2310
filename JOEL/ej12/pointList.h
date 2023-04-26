#include <iostream>
#include <vector>

using namespace std;

class pointList
{
    vector<point> vec;

public:
    pointList();
    pointList(const pointList &a);
    pointList(const vector<point> &a);
    pointList &operator=(const pointList &p);
    pointList &operator=(const vector<point> &a);
    ~pointList();

    point centroide();
    pointList centroide_e();
    point escalado(double a);
    point maxEfrompoint(const point &a);
    void bubbleSort();
    void grahamHull();

    void addPoint(point a);
    point getPoint(int i);
    vector<point> getVec();

    friend ostream &operator<<(ostream &out, pointList &a);
    friend pointList ce_routine(pointList &a);
};
