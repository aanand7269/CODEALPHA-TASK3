
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Bank {
public:
    string accountNo;
    string name;
    float balance;

    void CreateAccount() {
        cout << "Enter account number: ";
        cin >> accountNo;
        cout << "Enter account name: ";
        cin >> name;
        cout << "Enter initial balance: ";
        cin >> balance;

        ofstream file(accountNo + ".txt");
        if (file.is_open()) {
            file << accountNo << endl;
            file << name << endl;
            file << balance << endl;
            file.close();
            cout << "Account created successfully!\n";
        } else {
            cout << "Error creating account.\n";
        }
    }

    bool loadAccount(string inputAccountNo) {
        ifstream file(inputAccountNo + ".txt");
        if (file.is_open()) {
            string accNum;
            getline(file, accNum);
            getline(file, name);
            file >> balance;
            file.close();
            accountNo = inputAccountNo;
            return true;
        } else {
            return false;
        }
    }

    void deposit() {
        float amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        updateAccount();
        cout << "Amount deposited successfully.\n";
    }

    void withdraw() {
        float amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            balance -= amount;
            updateAccount();
            cout << "Amount withdrawn successfully.\n";
        }
    }

    void checkBalance() {
        cout << "Account Number: " << accountNo << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: $" << balance << endl;
    }

    void updateAccount() {
        ofstream file(accountNo + ".txt");
        if (file.is_open()) {
            file << accountNo << endl;
            file << name << endl;
            file << balance << endl;
            file.close();
        }
    }
};

int main() {
    int choice;
    Bank acc;
    string accountN;

    while (true) {
        cout << "\n===== BANK SYSTEM =======\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            acc.CreateAccount();
            break;
        case 2:
            cout << "Enter account number: ";
            cin >> accountN;
            if (acc.loadAccount(accountN))
                acc.deposit();
            else
                cout << "Account not found.\n";
            break;
        case 3:
            cout << "Enter account number: ";
            cin >> accountN;
            if (acc.loadAccount(accountN))
                acc.withdraw();
            else
                cout << "Account not found.\n";
            break;
        case 4:
            cout << "Enter account number: ";
            cin >> accountN;
            if (acc.loadAccount(accountN))
                acc.checkBalance();
            else
                cout << "Account not found.\n";
            break;
        case 5:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
