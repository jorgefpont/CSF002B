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
    cout << "E to x = " << res << endl;

}

int main() {
    double x;
    int n;
    cout << "Enter x and n(num terms): ";
    cin >> x >> n;
    etox(x, n);
    return 0;
}
