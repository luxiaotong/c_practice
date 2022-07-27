#include <iostream>

using namespace std;

int main()
{
    int index = 1;
    while (index <= 5)
    {
        cout << index << endl;
        index++;
    }

    index = 1;
    do
    {
        cout << index << endl;
        index++;
    } while (index <= 5);

    int nums[] = {1, 2, 5, 7, 3};
    for (int i = 0; i < 5; i++)
    {
        cout << "nums[" << i << "] = " << nums[i] << endl;
    }

    return 0;
}