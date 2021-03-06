#ifndef MC_H
#define MC_H
#include <iostream>
#include <array>

//#include "maths.h"

class MarkovChainMonteCarlo {
    private:
        using mcmc_state_t = double; //I want this to be vector or arrray.
        using mcmc_time_t  = int;
        mcmc_state_t m_x0;
        mcmc_state_t m_xt;
        mcmc_time_t m_t;
        std::string m_pdf_name;

    public:
        MarkovChainMonteCarlo(){
            m_x0 = 0.0;
            m_xt = 0.0;
            m_t  = 0;
        };

        ~MarkovChainMonteCarlo(){ };
        
        void print(){
            std::cout << "This is MCMC class." << std::endl;
            std::cout << m_x0 << ' ' << m_t << std::endl;
        };
        
        void set_pdf(std::string pdf_name){
            m_pdf_name = pdf_name;
            std::cout << "Prob. Density Function: " << pdf_name << std::endl;        
        
        };

        void potential_function();

        void run(bool verbose = 0);
        void output();
};

#endif