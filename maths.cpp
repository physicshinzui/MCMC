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

std::vector<float>  RandomNumGenerator::LinearCongruentialGenerators(){

};

//*This main function tests the class RandomNumGenerator.
// int main(){
//     RandomNumGenerator gen;
//     gen.print();
//     std::vector<float> seq { gen.generate(5)};
//     for (auto num : seq) {
//         std::cout << num << std::endl;
//     }
// }