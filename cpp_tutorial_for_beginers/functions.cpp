#include <iostream>
#include <cmath>

using namespace std;

void sayHi(string name, int age);

int main()
{
    sayHi("Lu", 60);
    sayHi("Tom", 45);
    sayHi("Steve", 19);
    return 0;
}

void sayHi(string name, int age)
{
    cout << "Hello " << name << " you are " << age << endl;
}