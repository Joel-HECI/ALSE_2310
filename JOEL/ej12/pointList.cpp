#include <iostream>
#include <cmath>
#include "punto2d.h"
#include "pointList.h"
#include "line.h"
#include <vector>

using namespace std;

pointList ce_routine(pointList &a)
{

    a.bubbleSort();
    pointList vec2;

    for (size_t i = 1; i < a.vec.size(); i++)
    {
        line e(a.vec[0], a.vec[i]);
        e.escalado(0.5);
        vec2.addPoint(e.getB());
    }
    return vec2;
}

pointList pointList::centroide_e()
{
    pointList vec2 = vec;

    for (size_t i = 0; i < vec.size() - 2; i++)
    {
        pointList vec3 = ce_routine(vec2);
        vec2.vec.clear();
        vec2 = vec3;
    }

    return vec2;
}

point pointList::centroide()
{

    double sumx = 0;
    double sumy = 0;

    for (point i : vec)
    {
        sumx += i.getX();
        sumy += i.getY();
    }

    return point(sumx / vec.size(), sumy / vec.size());
}

point pointList::escalado(double a)
{
}

void pointList::bubbleSort()
{
    bool again = false;
    point aux;
    do
    {
        again = false;

        for (size_t i = 0; i < vec.size() - 1; i++)
        {
            if (vec[i].angulo() > vec[i + 1].angulo())
            {
                aux = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = aux;
                again = true;
            }
            else
            {
                if (vec[i].angulo() == vec[i + 1].angulo())
                {
                    if (vec[i].magnitud() > vec[i + 1].magnitud())
                    {
                        aux = vec[i];
                        vec[i] = vec[i + 1];
                        vec[i + 1] = aux;
                        again = true;
                    }
                }
            }
        }
    } while (again);
}

void pointList::grahamHull()
{
    for (size_t i = 1; i < vec.size() - 1; i++)
    {
        int angl = angulo3puntos(vec[i - 1], vec[i], vec[i + 1]);

        if (angl > 0)
        {
            continue;
        }
        else
        {

            vec.erase(vec.begin() + i);
            i++;
        }
    }
}

point pointList::maxEfrompoint(const point &a)
{

    point max = vec[0];
    for (point i : vec)
    {
        if (i.distancia(a) > max.distancia(a))
        {
            max = i;
        }
    }
    return max;
}
pointList::pointList()
{
    vector<point> vec;
}

void pointList::addPoint(point a)
{
    vec.push_back(a);
}
point pointList::getPoint(int i)
{
    return vec[i];
}
vector<point> pointList::getVec()
{
    return vec;
}
pointList::~pointList()
{
    vec.clear();
}

pointList::pointList(const pointList &a)
{
    for (point i : a.vec)
    {
        vec.push_back(i);
    }
}
pointList::pointList(const vector<point> &a)
{
    for (point i : a)
    {
        vec.push_back(i);
    }
}
pointList &pointList::operator=(const pointList &a)
{

    for (point i : a.vec)
    {
        vec.push_back(i);
    }
}

pointList &pointList::operator=(const vector<point> &a)
{
    delete this;
    for (point i : a)
    {
        vec.push_back(i);
    }
}

ostream &operator<<(ostream &out, pointList &a)
{
    for (point i : a.vec)
    {
        out << i << endl;
    }
    return out;
}