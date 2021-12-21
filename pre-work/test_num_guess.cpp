#include <iostream>
#include <sstream>

using namespace std;

// Give the user 6 chances to guess the secret number n (0-10). If they get it,
// say so and return true. Else say so and return false.

bool play_game(int n) {
// TODO - Your code here
    string user_input;
    int max_guesses = 6;
   
    cout << "Welcome to my number guessing game\n\n";

    for (int i = 0; i < max_guesses; i++)
    {
        cout << "Enter your guess: ";
        stringstream ss;
        int x = 0;
        getline (cin, user_input);
        ss << user_input;
        ss >> x;
        //cout << "You entered: " << x << endl;
        
        if (x == n)
        {
            cout << "You found it in " << i+1 << " guess(es)\n\n4";
            break;
        }

        else if (x != n && i == 5)
        {
            cout << "I'm sorry. You didn't find my number.\nIt was " << n << endl << endl;
        }
    }
    
    return(true);
}

int main(){
    play_game(7);
    return(0);
}