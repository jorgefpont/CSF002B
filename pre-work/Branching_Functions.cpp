// Student ID: none yet, WInter 2022
//
// Branching_Functions.cpp
// 2a-Lab-03

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// This function returns the mean the three numbers passed
// in as parameters

double mean_of_3(int n1, int n2, int n3) {

    double mean = ( static_cast<double> (n1) +
                    static_cast<double> (n2) +
                    static_cast<double> (n3) ) / 3.0;
    return(mean);

}


// This function returns the maximum of the 5 given numbers

int max_of_5(int n1, int n2, int n3, int n4, int n5) {

    std::vector<int> alist = {n1, n2, n3, n4, n5};
    int max_num = alist[0];

    for (int item : alist) {
        if (item > max_num) {
            max_num = item;
        }
    }
    return(max_num);
}

// This function returns the minimum of the 5 given numbers

int min_of_5(int n1, int n2, int n3, int n4, int n5) {

    std::vector<int> alist = {n1, n2, n3, n4, n5};
    int min_num = alist[0];

    for (int item : alist) {
        if (item < min_num) {
            min_num = item;
        }
    }
    return(min_num);
}

/*
// Given three lengths, this function returns whether they can be the
// sides of some triangle

bool sides_make_triangle(int a, int b, int c) {
// TODO - YOUR CODE HERE
}

// Given three angles as integer degrees, this function returns whether
// they can be internal angles of some triangle

bool angles_make_triangle(int A, int B, int C) {
// TODO - YOUR CODE HERE
}

// Returns true if the year yyyy is a leap year and false if not.
bool is_a_leap_year(int yyyy) {
// TODO - YOUR CODE HERE
}
*/