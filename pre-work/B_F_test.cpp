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
    bool res4_1 = sides_make_triangle(10, 15, 20);
    bool res4_2 = sides_make_triangle(10, 10, 20);
    bool res4_3 = sides_make_triangle(942,7478,8991);
    cout << "Triangle Sides\n";
    cout << res4_1 << ", " << res4_2 << ", " << res4_3 << endl;

    // Test angles_make_triangle
    bool res5_1 = angles_make_triangle(45, 45, 90);
    bool res5_2 = angles_make_triangle(30, 60, 85);
    cout << "Triangle Angles\n";
    cout << res5_1 << ", " << res5_2 << endl;


    // Test is_a_leap_year
    bool res6_1 = is_a_leap_year(2012);
    bool res6_2 = is_a_leap_year(2013);
    cout << "Leap Year\n";
    cout << res6_1 << ", " << res6_2 << endl;
    return(0);
    
}