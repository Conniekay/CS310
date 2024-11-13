/*This program takes input from the user in feet and inches and converts it to centimeters.*/

#include <iostream>
#include <stdexcept>
using namespace std;

//Exceptions
class negativeNumber : public runtime_error {
public:
    negativeNumber() : runtime_error("Negative number entered") {}
};

class nonNumber : public runtime_error {
public:
    nonNumber() : runtime_error("Non-number entered") {}
};

int main() {
    double feet, inches;
    bool validInput = false;

    while (!validInput) {
        try {
            cout << "Enter feet: ";
            cin >> feet;
            if (!cin) {                
                throw nonNumber();
            }
            if (feet < 0) throw negativeNumber();

            cout << "Enter inches: ";
            cin >> inches;
            if (!cin) {                
                throw nonNumber();
            }
            if (inches < 0) throw negativeNumber();

            validInput = true;
        }
        catch (const negativeNumber& e) {
            cout << e.what() << ". Please enter non-negative numbers.\n";
        }
        catch (const nonNumber& e) {
            cout << e.what() << ". Please enter a valid number.\n";
            cin.ignore(1000, '\n'); 
        }
    }

    // Conversion calculation
    double totalInches = (feet * 12) + inches;
    double centimeters = totalInches * 2.54;

    cout << "The length in centimeters is " << centimeters << " cm" << endl;

    return 0;
}