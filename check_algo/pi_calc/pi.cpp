#include <iostream> 
#include <cstdlib>
#include <ctime> 
#include <fstream>
#include <cmath>
void calcPi(int niter);

void calcPi(int niter) {
    time_t now;  //time_t object
    time (&now); // time() makes a pointer point to the current time value. 

    //Random seed from the current time
    std::srand(now);

    std::ofstream fout ("pi_converg.csv");
    std::ofstream foutSqrt ("pi_sqrtK.csv");

    fout << "Iter" << ", " << "Pi" << "\n";
    foutSqrt << "Iter^{-1/2}" << ", " << "Pi" << "\n";

    // the number of points in x^2 + y^2 = 1
    int n_in { 0 }; 

    // Put random points on a plane iteratively, calculating the ratio of n_in to No of iteration. 
    for (int iter {0}; iter < niter; ++iter) {
        //random numbers x and y are generated, randing from 0 to 1.
        double x {(double)std::rand()/RAND_MAX};
        double y {(double)std::rand()/RAND_MAX};

        if (x*x + y*y < 1.0) {
            ++n_in;
        }
        //printf("%d   %.10f\n", iter, (double)n_in/iter); 
        fout << iter << ", " << (double)n_in/iter << "\n";
        foutSqrt << std::pow(iter, -0.5) << ", " << (double)n_in/iter << "\n";
        
    }
    fout.close();
    foutSqrt.close();
}

int main() {
    calcPi(10000); //10000 iteration
}