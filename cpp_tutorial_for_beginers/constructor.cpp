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
        title = "no title";
        author = "no author";
        pages = 0;
    }
    Book(string aTitle, string aAuthor, int aPages)
    {
        title = aTitle;
        author = aAuthor;
        pages = aPages;
        cout << "Creating Object: " << endl;
        cout << title << endl;
        cout << author << endl;
        cout << pages << endl;
    }
};

int main()
{
    Book book1("Haary Potter", "JK Rowling", 500);
    Book book2("Lord of the Rings", "Tolkein", 700);
    Book book3;
    cout << book3.title << endl;
    return 0;
}