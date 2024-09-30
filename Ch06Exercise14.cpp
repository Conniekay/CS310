//This program gets the hourly rate, the consulting time, whether the person has low income, then calculates the total bill.

#include <iostream>
#include <iomanip>
using namespace std;

 double billingAmount(double hourlyRate, int consultingTime, bool lowIncome) {
    double billingAmount = 0.0;

    if (lowIncome)
    {
        if (consultingTime > 30)
        {
            int extraTime = consultingTime - 30;
            billingAmount = (hourlyRate * 0.4) * (extraTime / 60.0);
        }
    } else
        {
           if (consultingTime > 20)
           {
               int extraTime = consultingTime - 20;
               billingAmount = (hourlyRate * 0.7) * (extraTime / 60.0);
           }
        } 
        return billingAmount;
    }
int main() {
       double hourlyRate;
       int consultingTime;
       bool lowIncome;
    
    
        cout << "Enter the hourly rate: ";
        cin >> hourlyRate;
        cout << "Enter the consulting time in minutes: ";
        cin >> consultingTime;
        cout << "Does the person have low income? (1 for yes, 0 for no): ";
        cin >> lowIncome;
           
        double totalBill = billingAmount(hourlyRate, consultingTime, lowIncome);
    
        cout << fixed << setprecision(2);
        cout <<"The billing amount is: $" << totalBill << endl;
        

    return 0;
}