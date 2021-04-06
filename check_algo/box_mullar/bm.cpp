#include <iostream>
#include <cmath> //sqrt, cos
#include <cstdlib> //rand, srand
//generate gauss random numbers by box muller

int box_muller() {
    double pi = 2.0*acos(0.0);
    int N = (int)pow(10,5);
    std::srand (10);

    for (int i { 0 }; i < N; ++i) {
        double q { (double)rand()/RAND_MAX } ;
        double p { (double)rand()/RAND_MAX };
        double x = sqrt(-2*log(p)) * cos(2 * pi * q);
        double y = sqrt(-2*log(p)) * cos(2 * pi * q);
        std::cout << x << " " << y << std::endl;

    }
    return 0;
}

int main() {
    box_muller();
}