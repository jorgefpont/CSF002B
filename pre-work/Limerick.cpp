// Student ID: none yet, WInter 2022
//
// Limerick.cpp
// 2a-Lab-01

#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>

using namespace std;

double eval_limerick(int dozen, int gross, int score) {
    
    double res = 
        (static_cast<double>(dozen) +
        static_cast<double>(gross) +
        static_cast<double> (score) +
        (3.0 * sqrt(4.0))) / 7.0 +
        (5.0 * 11.0);

    return(res);

}

int main(int argc, const char * argv[]) {

    int dozen, gross, score;

    if (argc < 4) {
        cerr << "Usage: limerick dozen-val gross-val score-val\n";
        exit(1);
    }

    istringstream(argv[1]) >> dozen;
    istringstream(argv[2]) >> gross;
    istringstream(argv[3]) >> score;

    double res = eval_limerick(dozen, gross, score);
    std::cout << res << std::endl;

    return(0);

}
