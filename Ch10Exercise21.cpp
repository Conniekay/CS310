//This program creates and stores bank accounts

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//Account class
class BankAccount {
private:
    string name;
    string type;
    int accountNumber;
    double balance;
    double intRate;
    static int nextAccountNumber;

public:
    BankAccount() {
        name = "";
        accountNumber = 0;
        balance = 0.0;
        intRate = 0.0;
        type = "";
}

BankAccount(string name, string type, double balance, double intRate);

    //getters
    string getName();
    string getType();
    int getAccountNumber();
    double getBalance();
    double getIntRate();
    //setters
    void setName(string name);
    void setType(string type);
    void setBalance(double balance);
    void setIntRate(double intRate);
    //other methods
    void deposit(double amount) {
        balance += amount;
    }
    void withdraw(double amount) {
        balance -= amount;
}
};
int BankAccount::nextAccountNumber = 10000;

//BankAccount constructor
BankAccount::BankAccount(string name, string type, double balance, double intRate) {
    this -> name=name;
    
    //check if type is valid
    if (type == "checking" || type == "savings") {
        this -> type=type;
    } else {
        cout << "Invalid account type. Type not set."<<endl;
    }
    
    this -> balance=balance;
    this -> intRate=intRate;
    this -> accountNumber=nextAccountNumber++;
}

//getters and setters
string BankAccount::getName() {
    return name;}
string BankAccount::getType() {
    return type;}
int BankAccount::getAccountNumber() {
    return accountNumber;}
double BankAccount::getBalance() {
    return balance;}
double BankAccount::getIntRate() {
    return intRate;}

void BankAccount::setName(string name) {
    this -> name=name;}
void BankAccount::setType(string type) {
    this -> type=type;}
void BankAccount::setBalance(double balance){
    this -> balance=balance;}
void BankAccount::setIntRate(double intRate){
    this -> intRate=intRate;}

//Bank class
class Bank {
private:
    BankAccount* accounts[10];
    int size;

public:
    Bank() {
        size = 0;
}
    //Function to add a new account
    void addAccount(BankAccount* account) {
        if (size < 10) {
            accounts[size] = account;
            size++;
        } else {
            cout << "Bank is full. Cannot add more accounts." << endl;
        }
    }
    //Function to display all accounts
    void displayAllAccounts() {
    for (int i = 0; i < size; i++) {
        string name; 
        cout << "Name: " << accounts[i]->getName() << endl;
        cout << "Account Type: " << accounts[i]->getType() << endl;
        cout << "Account Number: " << accounts[i]->getAccountNumber() << endl;
        cout << "Balance: " << accounts[i]->getBalance() << endl;
        cout << "Interest Rate: " << accounts[i]->getIntRate() << endl;
        }
    }
};

//Main function
int main() {
    Bank bank;

    //Create bank accounts
    for (int i=0; i<10; i++) {
        string name, type;
        double balance, intRate;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter account type (checking or savings): ";
        cin >> type;
        cout << "Enter balance: ";
        cin >> balance;
        cout << "Enter interest rate  (2% is .02): ";
        cin >> intRate;

        //Create bank account object
        BankAccount* account = new BankAccount(name, type, balance, intRate);
        bank.addAccount(account);

        //Ask user if they want to add another account
        char choice;
        do{
        cout << "Do you want to add another account? (y/n): ";
        cin >> choice;
        
        if (choice == 'y') {
            break;
        } else if (choice == 'n') {
            break;
        } else {
            cout << "Invalid choice. Please enter y or n." << endl;
        }
    }
    while (choice != 'y' && choice != 'n');

    if (choice == 'n') {
        break;
    }
    
    }
    //Display all accounts
    bank.displayAllAccounts();
    return 0;
}
