#include <iostream>

using namespace std;

int power(int base, int powNum)
{
    int result = 1;
    for (int i = powNum; i > 0; i--)
    {
        result *= base;
    }
    return result;
}

int main()
{
    cout << power(2, 0) << endl;
    cout << power(2, 4) << endl;
    cout << power(2, 16) << endl;
    return 0;
}