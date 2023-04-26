#include <iostream>
#include <cmath>
#include "punto2d.h"
#include "line.h"
#include "pointList.h"

using namespace std;

int main()
{
    line a(point(4, 6), point(-4, -10));

    pointList b;

    b.addPoint(point(3.12, 45.7));
    b.addPoint(point(-25.4, 34.4));
    b.addPoint(point(-12.4, 4));
    b.addPoint(point(8.34, -9.23));
    b.addPoint(point(34.6, 9.99));
    b.addPoint(point(12, -23));
    b.addPoint(point(23.5, 34.8));
    b.addPoint(point(6, 13));
    b.bubbleSort();
    cout << b << endl;
    point cent = b.centroide();
    cout << cent << endl;

    pointList c = ce_routine(b);
    cout << c << endl;
    pointList d = ce_routine(c);
    cout << d << endl;
    pointList e = ce_routine(d);
    cout << e << endl;
    pointList f = ce_routine(e);
    cout << f << endl;
    pointList g = ce_routine(f);
    cout << g << endl;
    pointList h = ce_routine(g);
    cout << h << endl;
    pointList i = ce_routine(h);
    cout << i << endl;

    return 0;
}