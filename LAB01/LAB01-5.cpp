#include <iostream>
using namespace std;

void duplicate(int& b)
{
    b*=2;
}

int main()
{
    int x = 25;
    cout << "The original value of x is " << x << endl;
    duplicate(x);
    cout << "The new value of x is " << x;
    return 0;
}