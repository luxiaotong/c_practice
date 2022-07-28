#include <iostream>

using namespace std;

class Student
{
public:
    string name;
    string major;
    double gpa;
    Student(string aName, string aMajor, double aGpa)
    {
        name = aName;
        major = aMajor;
        gpa = aGpa;
    }

    bool hasHonors()
    {
        return gpa >= 3.5;
    }
};

int main()
{
    Student student1("Jim", "Bussiness", 2.4);
    Student student2("Pam", "Art", 3.6);

    cout << student1.hasHonors() << endl;
    cout << student2.hasHonors() << endl;
    return 0;
}