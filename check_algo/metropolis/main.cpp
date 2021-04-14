#include <iostream> 
#include <cmath> 
#include <ctime>
#include <cstdlib>
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
        , where dx is a random number ranging from -c to c. dx must be equally sampled within the range in order for detailed balance.
        dx is taken randomly from -c <= dx <= c.

    Metropolis test:
        A random number r within [0,1] is generated.
        if  r < exp(S(x_i) - S(x')):
            Accept the candidate x' and x_{i+1} = x'
        else: 
            Reject it and x_{i+1} = x_i


*/

// Gaussian: S = 0.5 * (x - mu)^2 / var 
template<typename T>
T S_gauss(T x, T mu = 0.0, T var = 1.0) 
{ //default is mean = 0, variance = 1
    double xx = (x - mu) * (x - mu);
    return 0.5 * xx / var;
}
template<typename T> 
T S_two_gauss(T x, T mu1 = -5.0, T mu2 = 5.0, T var1 = 1.0, T var2 = 1.0)
{ 
    double exp1 = exp(-0.5 * (x + mu1) * (x + mu1) / var1 );
    double exp2 = exp(-0.5 * (x + mu2) * (x + mu2) / var2 );
    return - log(exp1 + exp2);
}

void metropolis(const int N, const double step_size, int seed) 
{
    std::srand(seed);
    
    //Initialization 
    double x_pre {10.0}; //initial state x0
    int n_accepts {0}; 

    //to monitor convergence
    double sum_x {0.0};
    double sum_xx {0.0};
    double mean {x_pre};
    double sqrt_mean {x_pre * x_pre};

    //Metropolis loop
    for (int iter { 0 }; iter < N; ++iter) {
        double dx = (double)std::rand() / RAND_MAX - 0.5; // dx range is [-0.5, 0.5] 
        dx = 2.0 * step_size * dx;                        // dx range is resized to [-step_size, step_size]. E.g., step_size=1 => [-1.0, 1.0]
        
        double x_suc = x_pre + dx; // an candidate state is made.
        
        //Metropolis test
        double metropolis_r = (double)std::rand() / RAND_MAX; //[0, 1]

        // double action_pre {S_gauss(x_pre)};
        // double action_suc {S_gauss(x_suc)};
        double action_pre {S_two_gauss(x_pre)};
        double action_suc {S_two_gauss(x_suc)};
        
        if (std::exp(action_pre - action_suc) > metropolis_r) {
            ++n_accepts;
            x_pre = x_suc;

        } else {
            x_suc = x_pre;
        }
        sum_x += x_suc;
        mean = (double)sum_x / iter;
        sum_xx += x_suc * x_suc;
        sqrt_mean = (double)sum_xx / iter; 

        std::cout << x_suc << ", "  << mean << ", " << sqrt_mean << std::endl;
    }
}

int main() 
{
    metropolis(1000000, 0.5, 10);
}