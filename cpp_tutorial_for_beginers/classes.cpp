#include <iostream>

using namespace std;

class Book
{
public:
    string title;
    string author;
    int pages;
    Book()
    {
        cout << "Creating Object" << endl;
    }
};

int main()
{
    Book book1;
    book1.title = "Harry Potter";
    book1.author = "JK Rowling";
    book1.pages = 500;

    cout << book1.title << endl;
    cout << book1.pages << endl;

    Book book2;
    book2.title = "Lord of the Rings";
    book2.author = "Tolkein";
    book2.pages = 600;

    cout << book2.title << endl;
    cout << book2.author << endl;

    return 0;
}