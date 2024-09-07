#include "Paint.h"

Paint::Paint()
{

}


Paint::Paint(int _x, int _y): x(_x), y(_y)
{
   
}

Paint::~Paint()
{

}


void Paint::set_x(int _x)
{
    x = _x;
}

void Paint::set_y(int _y)
{
    y = _y;
}

int Paint::get_x() const
{
    return x;
}

int Paint::get_y() const
{
    return y;
}

void Paint::set_xy(int _x, int _y)
{
    x = _x;
    y = _y;
}

 bool operator==(const Paint& a, const Paint& b) {
    return (a.get_x() == b.get_x()) && (a.get_y() == b.get_y());
} 