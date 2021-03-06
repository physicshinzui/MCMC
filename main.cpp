#include <iostream>
#include "mcmc.h"
//#include "maths.h"

int main() {
    MarkovChainMonteCarlo MCMC;
    MCMC.print();
    MCMC.set_pdf("cano");
    MCMC.run(1);
}