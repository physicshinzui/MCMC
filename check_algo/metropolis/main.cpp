#include <iostream> 
#include <cmath> 

/*
This program implements Metropolis algorithm.

P(x) = exp(-S(x)) / Z, where S is called action and Z is partition function. 
S(x) is a continuous function with respect to real number x.
In Gussian integra, S = x^2/2 and Z = sqrt(2 * pi)
Unfortunately, in most cases, we know S(x) but not Z.

Algorithm: 

initiaization
    - x0

Update and Metropolis test:
    Update:
        x0 -> x1 ->  ... -> xn
        A candidate of the next coordinates is given by x' = x_i + dx
        , where Dx is a random number ranging from -c to c. Dx must be equally sampled within the range in order for detailed balance.
        Dx was taken randomly from -c <= dx <= c.

    Metropolis test:
        A random number r within [0,1] is generated.
        if  r < exp(S(x_i) - S(x')):
            Accept the candidate x' and x_{i+1} = x'
        else: 
            Reject it and x_{i+1} = x_i


*/


int main() {

}