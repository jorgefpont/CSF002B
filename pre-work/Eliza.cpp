//Student ID: ​ n/a
//TODO - Replace the number above with your actual Student ID
// Eliza.cpp
// 2a.Lab-05-Eliza

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
/*
Return a new string in which the letters (lowercase) a, e, i, o, and u
have been replaced by the next vowel in the sequence aeiou. Replace u by a.
Note that the string is passed in by reference. So the caller may not
rely on the result being returned.
*/

string rotate_vowels(string s) {
    string res;
    for (size_t i=0; i<s.length(); i++) {
        if (s[i] == 'a')
            res += 'e';
        else if (s[i] == 'e')
            res += 'i';
        else if (s[i] == 'i')
            res += 'o';
        else if (s[i] == 'o')
            res += 'u';
        else if (s[i] == 'u')
            res += 'a';
        else
            res += s[i];      
    }
    return(res);
}

// Return a string in which all occurrences of s have been replaced by th
string lispify (string s) {
    string res;
    for (size_t i=0; i<s.length(); i++) {
        if (s[i] == 's') {
            res += "th";
        }
        else{
            res += s[i];
        }

    }
    return res;
}


// Enter the user-interaction loop as described earlier
void enter() {
// TODO - Your code here
    string input;
    bool done = false;

    // initial question
    cout << "What?" << endl;

    // conditions
    while (done == false) {

        // get user input
        stringstream ss;
        getline (cin, input);

        if (input == "") {
            cout << "What?" << endl;
        }
        else {
            cout << input << endl << endl;
        }

        if (input.find("!") < input.length()) {
            cout << "OMG! You don't say!! " 
                << input << "!!!!!" << endl;
        }

        else if (input.find("why") < input.length()) {
            cout << "I'm sorry, I don't like questions that contain what or why." 
            << endl;

        }

        else if (input.find("what") < input.length()) {
            cout << "I'm sorry, I don't like questions that contain what or why." 
            << endl;
        }

        else if (input.find("s") < input.length()) {
            cout << "Interethting. When did you thtop thtopping your thibilanth?"
            << endl << lispify(input) << "! Sheesh! Now what?" << endl;
        }

        else if (input == "quit" || input == "Quit" ||
                 input == "bye" || input == "Bye") {
            done = true;
        }

        else {
            int pct = rand()%10;
            if (pct > 7 && input != "") {
                cout << "Huh? Why do you say: "
                << input << "?" << endl;
            }
            else if (pct < 8 && input != "") {
                cout << rotate_vowels(input) << "?" << endl;
            }
        }

    }

    cout << "Ok bye. Nice being a force of change in your life.\n";

}
