#include<iostream>
#include<stdlib.h>
#include<limits>
using namespace std;

int main() {
    srand(time(NULL));
    int num  = rand() % 100;
    int guess;
    int total = 0;
    bool isnum;

    while (guess != num) {
        if (total > 2) {
            cout << "Too many guesses. You lose!" << endl;
            break;
        }

        if (total < 1) {
            cout << "Guess the number between 0 and 100: " << endl;
        }

        if (total > 1) {
            cout << "Last guess!" << endl;;
        }

        cin >> guess;

        if (cin.fail()) {
            isnum = false;
            cout << "Not a number. Guess again!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            isnum = true;
        }

        if (isnum == true && total <= 1) {
            if (guess < num) {
                cout << "Too low, guess again!" << endl;
            } else if (guess > num) {
                cout << "Too high, guess again!" << endl;
            }
        }

        total += 1;
    }

    if (isnum == true && total < 2) {
        cout << "You win!" << endl;
        cout << "Total guesses = " << total << endl;
    }

    return 0;
}
