#ifndef POINT_H
#define POINT_H

using namespace std;

class Point
{
    public:
    int X;
    int Y;
    
    Point () {}

    Point (int x, int y)
    {
        X = x;
        Y = y;
    }

    Point& operator= (const Point& point)
    {
        if (this == &point) {
            return *this;
        }

        X = point.X;
        Y = point.Y;

        return *this;
    }

    bool operator== (const Point& point) const
    {
        if (X == point.X && Y == point.Y) {
            return true;
        } else {
            return false;
        }
    }

    bool operator!= (const Point& point) const
    {
        return (X != point.X || Y != point.Y);
    }
};

#endif