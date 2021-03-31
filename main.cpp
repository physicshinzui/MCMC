#include <iostream>
#include "mcmc.h"
#include "maths.h"
#include <vector>

int main() {
    MarkovChainMonteCarlo MCMC;
    MCMC.print();
    MCMC.set_pdf("cano");
    MCMC.run(1);

    RandomNumGenerator Rgen;
    Rgen.print();
    std::vector<float> rand_nums { Rgen.generate(5) };
    for (auto element : rand_nums) { std::cout << element << std::endl; }
}