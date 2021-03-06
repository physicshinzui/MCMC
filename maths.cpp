#include <time.h>
#include <iostream>
#include <vector>
#include "maths.h"

void RandomNumGenerator::generate(std::vector<float> &sequence) {
    //std::cout<<"Random numbers generated between 0 and 1:"<<std::endl;
    std::srand( (unsigned)time(NULL) );
    
    for (int i = 0; i < (int)sequence.size(); i++) {
        float random_no = (float) rand()/RAND_MAX; 
        sequence.at(i) = random_no;
        //std::cout << sequence.at(i) << std::endl;
    }
}

int main(){
    RandomNumGenerator gen;
    gen.print();
    std::vector<float> seq(5);
    gen.generate(seq);
    std::cout << seq.at(0) << std::endl;
}