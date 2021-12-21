// Student ID: ​ none yet
//Looping_Functions.cpp
//Created by Anand Venkataraman on 8/9/19.
//Copyright © 2019 Anand Venkataraman. All rights reserved.

#include <iostream>
#include <sstream>
#include<vector>

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

// Calculate e^x using the series summation up to exactly the first
// n terms including the 0th term.
double etox(double x, size_t n) {
// TODO - Your code here
    vector<double> powers(n, 1);
    vector<double> factorials(n, 1);

    for (int i=1; i<n; i++) {
        powers[i] = powers[i] * x;
        factorials[i] = factorials[i-1] * i;

        for (int j=2; j<n; j++) {
            powers[j] = powers[j-1] * x;
        }
    }

    double res = 0;
    for (int i=0; i<n; i++) {
        //cout << powers[i] << " -- " << factorials[i] << endl;
        res = res + (powers[i]/factorials[i]);
    }
    cout << "E to x = " << res << endl;
}


// Return the number of occurrences of char c in string s
size_t count_chars(string s, char c) {
// TODO - Your code here
}
// Use Euclid's algorithm to calculate the GCD of the given numbers

size_t gcd(size_t a, size_t b) {
// TODO - Your code here
}

// Return a string of the form n1,n2,n3,... for the given AP.

string get_ap_terms(int a, int d, size_t n) {
// TODO - Your code here
}

// Return a string of the form n1,n2,n3,... for the given GP.

string get_gp_terms(double a, double r, size_t n) {
// TODO - Your code here
}

double get_nth_fibonacci_number(size_t n) {
// TODO - Your code here
}