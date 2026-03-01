#include <iostream>
#include <string>
#include "BankAccount.h"
using namespace std;

int main()
{
    // name is required
    string name;
    cout << "Enter first name of the customer: ";
    cin >> name;

    // creating a BankAccount object with 0 balances initially
    BankAccount b1(name, 0, 0);

    int c = 1; // menu choice
    double amount; // for any amount input
    while (c > 0 && c < 7)
    {
        // menu choices
        cout << "\n===== Bank Account Menu =====\n";
        cout << "1. Deposit to Checking Account\n";
        cout << "2. Withdraw from Checking Account\n";
        cout << "3. Deposit to Savings Account\n";
        cout << "4. Withdraw from Savings Account\n";
        cout << "5. Transfer from Checking to Savings\n";
        cout << "6. Display Account Details\n";
        cout << "Enter your choice (0 to exit): ";
        cin >> c;

        // runs while c not zero
        switch (c)
        {
        case 1:
            cout << "Enter amount to deposit in Checking: ";
            cin >> amount;
            b1.DepositChecking(amount);
            break;

        case 2:
            cout << "Enter amount to withdraw from Checking: ";
            cin >> amount;
            b1.WithdrawChecking(amount);
            break;

        case 3:
            cout << "Enter amount to deposit in Savings: ";
            cin >> amount;
            b1.DepositSavings(amount);
            break;

        case 4:
            cout << "Enter amount to withdraw from Savings: ";
            cin >> amount;
            b1.WithdrawSavings(amount);
            break;

        case 5:
            cout << "Enter amount to transfer from Checking to Savings: ";
            cin >> amount;
            b1.TransferToSavings(amount);
            break;

        case 6:
            cout << "\n--- Account Details ---\n";
            cout << "Customer Name: " << b1.GetName() << endl;
            cout << "Checking Balance: " << b1.GetChecking() << endl;
            cout << "Savings Balance: " << b1.GetSavings() << endl;
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }
    }

    return 0;
}
