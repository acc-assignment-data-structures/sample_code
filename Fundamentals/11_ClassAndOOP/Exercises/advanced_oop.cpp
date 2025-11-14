#include <iostream>
#include <string>
using namespace std;

/**
 * Advanced OOP Features:
 * - Static members and methods
 * - Friend functions
 * - Operator overloading
 * - Const member functions
 */

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;
    
    // Static member - shared by all instances
    static int totalAccounts;
    static double totalBankBalance;

public:
    // Constructor
    BankAccount(string holder, int accNum, double initialBalance = 0.0) {
        accountHolder = holder;
        accountNumber = accNum;
        balance = initialBalance;
        totalAccounts++;
        totalBankBalance += initialBalance;
    }

    // Destructor
    ~BankAccount() {
        totalAccounts--;
        totalBankBalance -= balance;
        cout << "Account closed for: " << accountHolder << endl;
    }

    // Const member functions (don't modify object state)
    string getAccountHolder() const {
        return accountHolder;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void displayInfo() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << balance << endl;
    }

    // Non-const member functions
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            totalBankBalance += amount;
            cout << "Deposited $" << amount << " to " << accountHolder 
                 << "'s account" << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            totalBankBalance -= amount;
            cout << "Withdrew $" << amount << " from " << accountHolder 
                 << "'s account" << endl;
        } else {
            cout << "Invalid withdrawal or insufficient funds!" << endl;
        }
    }

    void transfer(BankAccount& recipient, double amount) {
        if (amount > 0 && amount <= balance) {
            this->withdraw(amount);
            recipient.deposit(amount);
            cout << "Transferred $" << amount << " from " << accountHolder 
                 << " to " << recipient.accountHolder << endl;
        } else {
            cout << "Transfer failed!" << endl;
        }
    }

    // Static member functions (can only access static members)
    static int getTotalAccounts() {
        return totalAccounts;
    }

    static double getTotalBankBalance() {
        return totalBankBalance;
    }

    static void displayBankStatistics() {
        cout << "\n=== Bank Statistics ===" << endl;
        cout << "Total Accounts: " << totalAccounts << endl;
        cout << "Total Bank Balance: $" << totalBankBalance << endl;
        cout << "=======================\n" << endl;
    }

    // Operator overloading: + (add balances)
    BankAccount operator+(const BankAccount& other) const {
        string combinedName = accountHolder + " & " + other.accountHolder;
        int newAccNum = accountNumber + other.accountNumber;
        double combinedBalance = balance + other.balance;
        return BankAccount(combinedName, newAccNum, combinedBalance);
    }

    // Operator overloading: ==
    bool operator==(const BankAccount& other) const {
        return accountNumber == other.accountNumber;
    }

    // Operator overloading: >
    bool operator>(const BankAccount& other) const {
        return balance > other.balance;
    }

    // Operator overloading: +=
    BankAccount& operator+=(double amount) {
        deposit(amount);
        return *this;
    }

    // Friend function declaration
    friend void compareAccounts(const BankAccount& acc1, const BankAccount& acc2);
    friend ostream& operator<<(ostream& out, const BankAccount& account);
};

// Initialize static members
int BankAccount::totalAccounts = 0;
double BankAccount::totalBankBalance = 0.0;

// Friend function definition (can access private members)
void compareAccounts(const BankAccount& acc1, const BankAccount& acc2) {
    cout << "\n=== Account Comparison ===" << endl;
    cout << "Account 1: " << acc1.accountHolder << " - Balance: $" 
         << acc1.balance << endl;
    cout << "Account 2: " << acc2.accountHolder << " - Balance: $" 
         << acc2.balance << endl;
    
    if (acc1.balance > acc2.balance) {
        cout << acc1.accountHolder << " has more money." << endl;
    } else if (acc1.balance < acc2.balance) {
        cout << acc2.accountHolder << " has more money." << endl;
    } else {
        cout << "Both accounts have equal balance." << endl;
    }
    cout << "=========================\n" << endl;
}

// Friend function: operator<< overloading
ostream& operator<<(ostream& out, const BankAccount& account) {
    out << "[" << account.accountHolder << " - Acc#" << account.accountNumber 
        << " - $" << account.balance << "]";
    return out;
}

int main() {
    cout << "=== Advanced OOP Features Demo ===" << endl;

    // Display initial bank statistics
    BankAccount::displayBankStatistics();

    // Creating accounts
    cout << "\n1. Creating bank accounts:\n" << endl;
    BankAccount acc1("John Doe", 1001, 1000.0);
    BankAccount acc2("Jane Smith", 1002, 1500.0);
    BankAccount acc3("Bob Johnson", 1003, 800.0);

    // Display bank statistics after creating accounts
    BankAccount::displayBankStatistics();

    // Using overloaded << operator
    cout << "\n2. Using overloaded << operator:\n" << endl;
    cout << "Account 1: " << acc1 << endl;
    cout << "Account 2: " << acc2 << endl;
    cout << "Account 3: " << acc3 << endl;

    // Performing transactions
    cout << "\n3. Performing transactions:\n" << endl;
    acc1.deposit(500.0);
    acc2.withdraw(300.0);
    acc1.transfer(acc3, 200.0);

    // Using operator overloading
    cout << "\n4. Using overloaded operators:\n" << endl;
    
    // Using +=
    acc1 += 100.0;
    cout << "After += operation: " << acc1 << endl;

    // Using >
    if (acc1 > acc3) {
        cout << acc1.getAccountHolder() << " has more money than " 
             << acc3.getAccountHolder() << endl;
    }

    // Using ==
    BankAccount acc4("John Doe", 1001, 2000.0);
    if (acc1 == acc4) {
        cout << "acc1 and acc4 have the same account number" << endl;
    }

    // Using friend function
    cout << "\n5. Using friend function:\n" << endl;
    compareAccounts(acc1, acc2);
    compareAccounts(acc2, acc3);

    // Display final bank statistics
    cout << "\n6. Final bank statistics:\n" << endl;
    BankAccount::displayBankStatistics();

    cout << "\n=== Program ending ===" << endl;
    return 0;
}
