//This program prompts the user for the time it takes to prepare a recipe and how much time is available. It then calculates how many recipes the user can make in the time available.

#include <iostream>
using namespace std;

int main()
{
    int a; //time to prepare a recipe
    int b; //additional time needed to prepare each recipe
    int t; //time available
    
    cout << "How long does it take to prepare the first recipe? ";
    cin >> a;

    cout << "How much additional time does it take to prepare each additional recipe? ";
    cin >> b;

    cout << "How much time do you have? ";
    cin >> t;

    int recipes = 0;
    int totalTime = 0;
    
    while (totalTime + a <= t)
        {
            recipes++;
            totalTime += a;
            a += b;
        }

    cout << "Bianca can prepare " << recipes << " recipes." << endl;

    return 0;
}