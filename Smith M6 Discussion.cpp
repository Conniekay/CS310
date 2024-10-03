#include <iostream>
using namespace std;

enum Weekday (Monday, Tuesday, Wednesday, Thursday Friday, Saturday, Sunday);

int main() {
    Weekday today = Friday;

    if (today == Friday)
        cout << "Woo Hoo! It's Friday!" << endl;
    else
        cout << "Keep going, it's not Friday yet." << endl;

    return 0;
}