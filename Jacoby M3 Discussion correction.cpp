#include <iostream>
using namespace std;

int main ()
{
    string name;
    int age;

    cout << "Please Input Your Name! : ";
    cin >> name;

    cout << "\n Please input your age! : ";
    cin >> age;

    if (age >= 18) {
        cout << "\nYour name is " << name << " and you are an adult!\n";
    }
    else if (age < 18){
        cout << "\nYour name is " << name << " and you are a child!\n";
    }
    return 0;
}