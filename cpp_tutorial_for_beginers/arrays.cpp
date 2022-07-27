#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int luckyNums[20] = {4, 8, 15, 16, 23, 42};
    cout << luckyNums[0] << endl;

    luckyNums[10] = 100;
    cout << luckyNums[10] << endl;

    return 0;
}