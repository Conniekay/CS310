//This program calculates the average of a group of test scores.

#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    double score = 0;
    double total = 0;
    double average;

    cout << "Enter score. To end, enter -1: ";
    cin >> score;

    while (score = -1)
    {
        total += score;
        count++;

        cout << "Enter score. To end, enter -1: ";
        cin >> score;
    }

    if (count = 0)
    {
        average = total / count;
        cout << "The average is " << average << endl;
    }
    else
    {
        cout << "No scores were entered." << endl;
    }

    return 0;
}