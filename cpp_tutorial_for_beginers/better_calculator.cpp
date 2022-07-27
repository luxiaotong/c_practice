#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num1, num2;
    char op;
    cout << "enter first number: ";
    cin >> num1;
    cout << "enter operator: ";
    cin >> op;
    cout << "enter second number: ";
    cin >> num2;

    int result;
    if (op == '+')
    {
        result = num1 + num2;
    }
    else if (op == '-')
    {
        result = num1 - num2;
    }
    else if (op == '*')
    {
        result = num1 * num2;
    }
    else if (op == '/')
    {
        result = num1 / num2;
    }
    else
    {
        cout << "Invalid Operator" << endl;
    }
    cout << result << endl;
    return 0;
}