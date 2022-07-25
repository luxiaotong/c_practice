#include <iostream>

using namespace std;

int main()
{
    string phrase = "Test Academy";
    cout << phrase << "\n";
    cout << phrase.length() << endl;

    cout << phrase[0] << endl;
    phrase[0] = 'B';
    cout << phrase << endl;

    cout << phrase.find("Academy", 0) << endl;

    int pos = phrase.find("acsd", 0);
    cout << pos << endl;

    string phrasesub = phrase.substr(5, 3);
    cout << phrasesub << endl;

    return 0;
}