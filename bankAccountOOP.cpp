
#include <iostream>
using namespace std;

class BankAccount {
public:
    BankAccount(string account_number, string account_holder, double balance) {
        this->account_number = account_number;
        this->account_holder = account_holder;
        this->balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " into account " << account_number << ". New balance is " << balance << "." << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds in account " << account_number << "." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << account_number << ". New balance is " << balance << "." << endl;
        }
    }

    void transfer(double amount, BankAccount& recipient) {
        if (amount > balance) {
            cout << "Insufficient funds in account " << account_number << "." << endl;
        } else {
            balance -= amount;
            recipient.balance += amount;
            cout << "Transferred " << amount << " from account " << account_number << " to account " << recipient.account_number << ". New balance for account " << account_number << " is " << balance << ". New balance for account " << recipient.account_number << " is " << recipient.balance << "." << endl;
        }
    }

private:
    string account_number;
    string account_holder;
    double balance;
};

int main() {
    BankAccount account1("123456", "Alice", 1000);
    BankAccount account2("654321", "Bob", 500);

    account1.deposit(500);
    account1.withdraw(200);
    account1.transfer(300, account2);

    return 0;
}
