/* This porgram uses c++11 random number generator to generate 25 real numbers between 10 and 100*/

#include <iostream>
#include <random>
using namespace std;

int main()
{
    random_device rdevice;
    default_random_engine num {rdevice()};
    uniform_int_distribution<unsigned int> randomNum{10,100};
    
    for (int i = 0; i < 25; i++) {
        cout << randomNum (num) << " ";
    }
        cout << endl;
  
    return 0;
}