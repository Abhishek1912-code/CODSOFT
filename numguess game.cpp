
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{
    srand(time(0));

    int secretNumber = rand() % 100 + 1;
    int guess;
    
    while (true) 
	{
        cout << "Guess the number between 1 and 100: ";
        cin >> guess;
        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number: " << secretNumber << endl;
            break;
        }
    }

    return 0;
}
