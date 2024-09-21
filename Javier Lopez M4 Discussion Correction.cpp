#include <iostream>
using namespace std;

int main() {
    int numberOfLoops;

    // Ask the user for the number of times to loop
    cout << "Enter the number of times to loop: ";
    cin >> numberOfLoops;

    // Loop the specified number of times
    for (int i = 1; i <= numberOfLoops; i++) {
        cout << "This is loop number: " << i << endl;
    }

    return 0;
}