//Simple testing function for dataset 
#include <vector>
#include <iostream>
#include "dataset.h"
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    dataset iris("iris.csv", 5);
    /*for(int i = 0; i < iris.length(); i++){
        std::cout << iris.iget()->getData(0) << std::endl;
    }*/
    
    cout << iris.get(0).getData(0) << endl;
    cout << iris.get(0).getData(3) << endl;
    
    vector <double> swag;
    
    for(int i =0;i<10;i++)
    {
    	swag.push_back(iris.get(i).getData(0));
    }
    
    
    cout << iris.get(0).getData(5) << endl;
    cout << iris.get(75).getData(5) << endl;
}


