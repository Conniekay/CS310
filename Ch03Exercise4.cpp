/*
  This program gets net balance, payment, d1, d2, and interest rate per month then outputs the interest.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    double netBalance;
    double payment;
    int d1;
    int d2;
    double interestRate;
    double averageDailyBalance;
    double interest;
    

    cout << "Enter the balance: ";
    cin >> netBalance;
    cout << "Enter the payment: ";
    cin >> payment;
    cout << "Enter the number of days in the billing cycle: ";
    cin >> d1;
    cout << "Enter the number of days payment is made before billing cycle: ";
    cin >> d2;
    cout << "Enter the interest rate per month (enter 15% as .15): ";
    cin >> interestRate;

    //This is the formula for the average daily balance
    averageDailyBalance = (netBalance * d1 - payment * d2) / d1;

    //This is the formula for interest
   interest = averageDailyBalance * interestRate;

    //Format the output to 2 decimal places and include a thousands separator
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);
    cout << "The interest is: $" << interest << endl;
  
    return 0;
}