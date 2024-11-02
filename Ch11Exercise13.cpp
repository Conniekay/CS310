/*This program manages bank accounts.
Getch() is much easier to figure out than cin.get.*/


#include <iostream>
#include <iomanip>
#include <conio.h> 
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    double balance;

public:
    // Constructors
    BankAccount() : accountNumber(0), balance(0.0) {}
    BankAccount(int accNumber, double initialBalance) : accountNumber(accNumber), balance(initialBalance) {}

    // Set the account number
    void setAccountNumber(int accNumber) {
        accountNumber = accNumber;
    }

    // Retrieve the account number
    int getAccountNumber() const {
        return accountNumber;
    }

    // Retrieve the balance
    double getBalance() const {
        return balance;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // Withdraw money
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }

    // Print account information
    virtual void printAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};
class CheckingAccount;

class CheckingAccount : public BankAccount {
private:
    double interestRate;
    double minBalance;
    double serviceCharges;

public:
    // Constructor
    CheckingAccount(int accNumber, double initialBalance, double rate, double minBal, double charges)
        : BankAccount(accNumber, initialBalance), interestRate(rate), minBalance(minBal), serviceCharges(charges) {}

    // Set and get the interest rate
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    double getInterestRate() const {
        return interestRate;
    }

    // Set and get the minimum balance
    void setMinimumBalance(double minBal) {
        minBalance = minBal;
    }

    double getMinimumBalance() const {
        return minBalance;
    }

    // Set and get the service charges
    void setServiceCharges(double charges) {
        serviceCharges = charges;
    }

    double getServiceCharges() const {
        return serviceCharges;
    }

    // Post interest to the account
    void postInterest() {
        double interest = balance * interestRate;
        deposit(interest);
    }

    // Check if balance is below minimum balance
    bool isBelowMinimumBalance() const {
        return balance < minBalance;
    }

    // Write a check (same as a withdrawal)
    void writeCheck(double amount) {
        withdraw(amount);
    }

    // Override the withdraw function to include service charge
    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            balance -= amount;
            if (balance < minBalance) {
                balance -= serviceCharges;
                cout << "Service charges applied. ";
            }
            cout << "New balance: $" << balance << endl;
        }
    }

    // Print account information
    void printAccountInfo() const override {
        BankAccount::printAccountInfo();
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
        cout << "Minimum Balance: $" << minBalance << endl;
        cout << "Service Charges: $" << serviceCharges << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    // Constructor
    SavingsAccount(int accNumber, double initialBalance, double rate)
        : BankAccount(accNumber, initialBalance), interestRate(rate) {}

    // Set and get the interest rate
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    double getInterestRate() const {
        return interestRate;
    }

    // Post interest
    void postInterest() {
        double interest = balance * interestRate;
        deposit(interest);
    }

    // Override the withdraw function
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }

    // Print account information
    void printAccountInfo() const override {
        BankAccount::printAccountInfo();
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
    }
};

int main() {
    char choice;
    BankAccount* account = nullptr;

    do {
        cout << "\nBank Account Menu:\n";
        cout << "1. Create Checking Account\n";
        cout << "2. Create Savings Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Post Interest\n";
        cout << "6. Print Account Information\n";
        cout << "Enter your choice (1-6): ";
       
        char menuChoice = _getche();
        cout << menuChoice << endl;
        

        switch (menuChoice) {
            case '1': { // Create Checking Account
                int accNumber;
                double balance, interestRate, minBalance, serviceCharges;
                cout << "Enter account number: ";
                cin >> accNumber;
                cout << "Enter initial balance: ";
                cin >> balance;
                cout << "Enter interest rate (2% is .02): ";
                cin >> interestRate;
                cout << "Enter minimum balance: ";
                cin >> minBalance;
                cout << "Enter service charges: ";
                cin >> serviceCharges;
                account = new CheckingAccount(accNumber, balance, interestRate, minBalance, serviceCharges);
                cout << "Checking account created.\n";
                break;
            }
            case '2': { // Create Savings Account
                int accNumber;
                double balance, interestRate;
                cout << "Enter account number: ";
                cin >> accNumber;
                cout << "Enter initial balance: ";
                cin >> balance;
                cout << "Enter interest rate (2% is .02): ";
                cin >> interestRate;
                account = new SavingsAccount(accNumber, balance, interestRate);
                cout << "Savings account created.\n";
                break;
            }
            case '3': { // Deposit
                if (account) {
                    double amount;
                    cout << "Enter deposit amount: ";
                    cin >> amount;
                    account->deposit(amount);
                } else {
                    cout << "No account exists.\n";
                }
                break;
            }
            case '4': { // Withdraw
                if (account) {
                    double amount;
                    cout << "Enter withdrawal amount: ";
                    cin >> amount;
                    account->withdraw(amount);
                } else {
                    cout << "No account exists.\n";
                }
                break;
            }
            case '5': { // Post Interest
                if (auto* checkAcc = dynamic_cast<CheckingAccount*>(account)) {
                    checkAcc->postInterest();
                    cout << "Interest posted to account.\n";
                } else if (auto* saveAcc = dynamic_cast<SavingsAccount*>(account)) {
                    saveAcc->postInterest();
                    cout << "Interest posted to account.\n";
                } else {
                    cout << "No account exists or unsupported account type.\n";
                }
                break;
            }
            case '6': { // Print Account Information
                if (account) {
                    account->printAccountInfo();
                } else {
                    cout << "No account exists.\n";
                }
                break;
            }
            default:
                cout << "Invalid choice. Please select a valid option.\n";
                break;
        }

        // Ask the user if they want to perform another operation
        cout << "Do you want to perform another operation? (y/n): ";
        choice = _getche();
        cout << choice << endl;
        

    } while (tolower(choice) == 'y');

    cout << "Exiting program...\n";
    return 0;
}