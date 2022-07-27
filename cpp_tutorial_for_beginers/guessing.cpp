#include <iostream>

using namespace std;

int main()
{
    int secretNum = 7;
    int guess;
    int guessCount = 0;
    int guessLimit = 3;

    while (secretNum != guess && guessCount < guessLimit)
    {
        cout << "Enter guess: ";
        cin >> guess;
        guessCount++;
    }
    if (secretNum == guess)
    {
        cout << "You win" << endl;
    }
    else
    {
        cout << "You lose" << endl;
    }

    return 0;
}