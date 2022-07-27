#include <iostream>
#include <cmath>

using namespace std;

double cube(double x)
{
    return x * x * x;
}

int main()
{
    cout << cube(3) << endl;
    return 0;
}