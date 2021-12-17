// Test for Branching_Functions.cpp
// 2a-Lab-03

#include <iostream>
#include <cmath>

using namespace std;

// Forward declarations of functions that will be used in this file
// before their definitions are encountered by the compiler
double mean_of_3(int n1, int n2, int n3);
int max_of_5(int n1, int n2, int n3, int n4, int n5);
int min_of_5(int n1, int n2, int n3, int n4, int n5);
bool sides_make_triangle(int a, int b, int c);
bool angles_make_triangle(int A, int B, int C);
bool is_a_leap_year(int year);

int main() {

    // Test mean
    double res1 = mean_of_3(4,6,8); 
    cout << res1 << endl;

    // Test max_of_5
    int res2_1 = max_of_5(1,2,3,4,5);
    int res2_2 = max_of_5(5,4,3,2,1);
    int res2_3 = max_of_5(4,3,5,2,1);
    cout << res2_1 << ", " << res2_2 << ", " << res2_3 << endl;

    // Test min_of_5
    int res3_1 = min_of_5(1,2,3,4,5);
    int res3_2 = min_of_5(5,4,3,2,1);
    int res3_3 = min_of_5(4,3,5,2,1);
    cout << res3_1 << ", " << res3_2 << ", " << res3_3 << endl;    

    // Test sides_make_triangle

    // Test angles_make_triangle

    // Test is_a_leap_year

    return(0);
    
}