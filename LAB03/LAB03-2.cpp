#include <iostream>

struct Point 
{
    double x;
    double y;
};

void move(Point &p, double dx, double dy) 
{
    p.x += dx;
    p.y += dy;
}

int main() 
{
    Point p {1.0, 2.0};
    move(p, 0.5, 1.0);
    std::cout << "(" << p.x << ", " << p.y << ")" << std::endl; // prints "(1.5, 3.0)"
    return 0;
}
