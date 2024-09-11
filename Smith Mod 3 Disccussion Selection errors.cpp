#include <iostream>
using namespace std;

int main()
{
    
    int age;
     cout << "Enter your age: ";
     cin >> age;

     if (age > 19 || age < 65) 
          cout << "You are an adult. " << endl;
     else if (age < 19)
          cout << "You are a child. " << endl;
     else if (age > 65)
          cout << "You are a senior citizen. " << endl;
     
     if (age && 18)
          cout << "You are old enough to vote. " << endl;
     
     return 0;
     }