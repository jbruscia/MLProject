//networktest.cpp
//Luke Duane
//testing feed forward implementation in Neural Network


#include <iostream>
#include <vector>
#include <cstdlib>
#include "network.h"
using namespace std;

int main(){
    vector<double> tmp;
    tmp.push_back(.2);
    tmp.push_back(.9);
    tmp.push_back(.8);
    tmp.push_back(.82);
    cout << "made vector" << endl;
    NeuralNetwork network1("../dataSets/credit.csv", 16);
    return 0;
}
