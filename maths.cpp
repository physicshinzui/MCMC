#include <time.h>
#include <iostream>
#include <vector>
#include "maths.h"

//void RandomNumGenerator::generate(std::vector<float> &sequence) {
std::vector<float> RandomNumGenerator::generate(int n_elements) {
    //std::cout<<"Random numbers generated between 0 and 1:"<<std::endl;
    std::srand( (unsigned)time(NULL) );
    std::vector<float> sequence(n_elements);
    for (int i = 0; i < (int)sequence.size(); i++) {
        float random_no = (float) rand()/RAND_MAX; 
        sequence.at(i) = random_no;
        //std::cout << sequence.at(i) << std::endl;
    }
    return sequence;
}

std::vector<int> RandomNumGenerator::linearCongruentialGenerator(){
    /*
    x_{n+1} = a * x_n + b (mod M)
    
    The values of a, b, and M were taken from Numerical Recipes (https://en.wikipedia.org/wiki/Numerical_Recipes). 
    a = 1664525
    b = 1013904223
    M = 2^32
    */
    const unsigned int a { 4 };
    const unsigned int b { 1 };
    const unsigned int M { 9 };
    unsigned x_pre { 0 }; // x0 or (aka. seed)

    std::vector<int> sequence(0);
    for (int i {0}; i < M ; ++i) {
        int x_suc = (a * x_pre + b) % M;
        sequence.push_back(x_suc);
        x_pre = x_suc;
    }
    return sequence;
}

//*This main function tests the class RandomNumGenerator.
int main(){
    RandomNumGenerator gen;
    gen.print();
    std::vector<float> seq { gen.generate(5)};
    for (auto num : seq) {
        std::cout << num << std::endl;
    }
    std::cout << std::endl;
    std::vector<int> seq_LGCs { gen.linearCongruentialGenerator() };
    for (auto num : seq_LGCs) {
        std::cout << num << std::endl;
    }

}