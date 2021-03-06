#include <iostream> 
#include <math.h> 
#include "mcmc.h"

void MarkovChainMonteCarlo::run(bool verbose) {
    if (verbose) std::cout << "running..." << std::endl;

    //(1) initialization
    //done by the constructor

    //(2) Iteration

    //2-1. genrate a candidate x' for next sample by picking from
    // the distribution g(x'|x_t)

    //the following is the test of exp function and works. 
        // double potential = 1.0;
        // const double gas_const = 0.59; //kcal/mol
        // const double tempeature = 300.0;
        // double term = - potential / (gas_const * tempeature);
        // double prob = exp(term);
        // std::cout << prob << std::endl;

    //2-2. Calculate the acceptance ratio a=f(x')/f(x_t)
    //, which will be used to decide whether to accept or reject the candidate. 
    // Because f is proportional to the density of P, we have that 
    // a = f(x')/f(x_t) = P(x')/P(x_t)

    //2-3. Accept or reject
        //i. generate a uniform random number u \in[0,1]
        
        //ii. if u <= a, accept the candidate by setting x_{t+1} = x'

        //iii. if u > a, reject the candidate and set x_{t+1} = x_t, instead.


}



