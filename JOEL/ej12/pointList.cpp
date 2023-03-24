#include <iostream>
#include <cmath>
#include "punto2d.h"
#include "pointList.h"
#include <vector>

using namespace std;

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
vector<point> pointList::bubbleOrdering()
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
    } while (again == true);
}
vector<point> pointList::grahamHull()
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
pointList::pointList(const pointList &a)
{
    for (point i : a.vec)
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

ostream &operator<<(ostream &out, pointList &a)
{
    for (point i : a.vec)
    {
        out << i << " ";
    }
    return out;
}