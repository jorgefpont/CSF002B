#include <iostream>
#include<vector>
using namespace std;

double etox(double x, int n) {

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
    return(res);
}

int gcd(int a, int b) {
// TODO - Your code here
    while (a != b) {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return(a);
}

int main() {
    double x;
    int n;
    cout << "Enter x and n(num terms): ";
    cin >> x >> n;
    cout << "E to x = " << etox(x, n) << endl << endl;

    cout << "GCD for 15/5, 210/45, 1024/99\n";
    cout << gcd(15,5) << ", " << gcd(210,45) << ", " << gcd(1024,99) << endl;

    return 0;
}
