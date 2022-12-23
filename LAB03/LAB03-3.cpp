#include <iostream>

struct Point
{
    int x;
    int y;
};

void movePoint(Point p, int dx, int dy)
{
    p.x += dx;
    p.y += dy;
}

int main()
{
    Point p = {1, 2};
    movePoint(p, 3, 4);
    std::cout << "(" << p.x << ", " << p.y << "X" << std::endl;
    return 0;
}