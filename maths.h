#ifndef MATHS_H
#define MATHS_H
#include <vector>
#include <time.h>
#include <iostream>

class RandomNumGenerator {
    private:

    public:
        RandomNumGenerator(){};
        ~RandomNumGenerator(){};
        void print(){std::cout << "It's me!" << std::endl;};
//        void generate(std::vector<float> &sequence);
        std::vector<float> generate(int n_elements);
        std::vector<int> linearCongruentialGenerator();
};

#endif