
#include <iostream>
using namespace std;

struct BankAccount {
    string account_number;
    string account_holder;
    double balance;
};

void deposit(BankAccount& account, double amount) {
    account.balance += amount;
    cout << "Deposited " << amount << " into account " << account.account_number << ". New balance is " << account.balance << "." << endl;
}

void withdraw(BankAccount& account, double amount) {
    if (amount > account.balance) {
        cout << "Insufficient funds in account " << account.account_number << "." << endl;
    } else {
        account.balance -= amount;
        cout << "Withdrew " << amount << " from account " << account.account_number << ". New balance is " << account.balance << "." << endl;
    }
}

void transfer(BankAccount& sender, BankAccount& recipient, double amount) {
    if (amount > sender.balance) {
        cout << "Insufficient funds in account " << sender.account_number << "." << endl;
    } else {
        sender.balance -= amount;
        recipient.balance += amount;
        cout << "Transferred " << amount << " from account " << sender.account_number << " to account " << recipient.account_number << ". New balance for account " << sender.account_number << " is " << sender.balance << ". New balance for account " << recipient.account_number << " is " << recipient.balance << "." << endl;
    }
}

int main() {
    BankAccount account1 = {"123456", "Alice", 1000};
    BankAccount account2 = {"654321", "Bob", 500};

    deposit(account1, 500);
    withdraw(account1, 200);
    transfer(account1, account2, 300);

    return 0;
}
