// Student ID: none yet, WInter 2022
//
// Teox.cpp
// 2a-Lab-01

#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>

using namespace std;

double etox_5_terms(double x) {

    double res = 1.0 + x + ((x*x)/2.0) + 
        ((x*x*x)/(3.0*2.0)) + ((x*x*x*x)/(4.0*3.0*2.0));
    return(res);
}

int main (int argc, char **argv) {

    string user_input;
    double x;

    cout << "Enter a value for x: ";
    getline(cin, user_input);
    istringstream(user_input) >> x;

    double res = etox_5_terms(x);
    cout << res << endl;

}