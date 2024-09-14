
//This program calculates how much an author will be paid for their book under three different payment plans and chooses the best one.

#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
         const double OPTION1_FIXED_PAYMENT = 25000.0; //$25,000

         const double OPTION2_ROYALTY_RATE = 0.125; // 12.5%

         const double OPTION3_RATE1 = 0.10; // 10% for the first 4000 copies
         const double OPTION3_RATE2 = 0.14; // 14% for copies beyond 4000
         const int OPTION3_THRESHOLD = 4000; // 4000 copies threshold

         double netPrice;
         int estimatedCopiesSold;

         // Get the net price and estimated number of copies from the user
         cout << "Enter the net price of each copy: $";
         cin >> netPrice;
         cout << "Enter the estimated number of copies to be sold: ";
         cin >> estimatedCopiesSold;

         // Option 1: Fixed payment
         double option1Royalties = OPTION1_FIXED_PAYMENT;

         // Option 2: 12.5% of each copy sold
         double option2Royalties = OPTION2_ROYALTY_RATE * netPrice * estimatedCopiesSold;

         // Option 3: 10% for first 4000 copies, 14% for additional copies
         double option3Royalties;
         if (estimatedCopiesSold <= OPTION3_THRESHOLD) {
             option3Royalties = OPTION3_RATE1 * netPrice * estimatedCopiesSold;
         } else {
             int additionalCopies = estimatedCopiesSold - OPTION3_THRESHOLD;
             option3Royalties = (OPTION3_RATE1 * netPrice * OPTION3_THRESHOLD) +
                                (OPTION3_RATE2 * netPrice * additionalCopies);
         }

         // Show the royalties for each option
         cout << fixed << setprecision(2);
         cout << "Option 1 pays: $" << option1Royalties << endl;
         cout << "Option 2 pays: $" << option2Royalties << endl;
         cout << "Option 3 pays: $" << option3Royalties << endl;

         // Select the best option
         if (option1Royalties > option2Royalties && option1Royalties > option3Royalties) {
             cout << "Option 1 is the best." << endl;
         } else if (option2Royalties > option1Royalties && option2Royalties > option3Royalties) {
             cout << "Option 2 is the best." << endl;
         } else {
             cout << "Option 3 is the best." << endl;
         }

         return 0;
}