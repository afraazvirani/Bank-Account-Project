#pragma once
#include <iostream>
#include <string>
using namespace std; // to avoid repetition of std::


class BankAccount // creating bank account
{
private:
  string customerName;
  double savingsAccountBalance, checkingAccountBalance;

public:
  // parameterized constructor only (can be made better with default, copy, and move constructors too)
  BankAccount(string newName, double chBalance, double sBalance) : customerName(newName), checkingAccountBalance(chBalance), savingsAccountBalance(sBalance) {}


  // setters and getters for access to private members
  void SetName(string newName) { customerName = newName; }
  string GetName() { return customerName; }
  void SetSavings(double balance) { savingsAccountBalance = balance; }
  double GetSavings() { return savingsAccountBalance; }
  void SetChecking(double balance) { checkingAccountBalance = balance; }
  double GetChecking() { return checkingAccountBalance; }

  // adds amount to checking balance if positive
  void DepositChecking(double amt) {
    if (amt > 0) {
      checkingAccountBalance += amt;
    }
  }
  
  // adds amount to savings balance if positive
  void DepositSavings(double amt) {
    if (amt > 0) {
      savingsAccountBalance += amt;
    }
  }

  // withdrawal occurs only if the amount is positive and available
  void WithdrawChecking(double amt) {
    if (amt > 0 && checkingAccountBalance >= amt)
    {
      checkingAccountBalance -= amt;
    } 
  }
  
  // withdrawal occurs only if the amount is positive and available
  void WithdrawSavings(double amt) {
    if (amt > 0 && amt <= savingsAccountBalance)
    {
      savingsAccountBalance -= amt;
    } 
  }


  // transfer possible only if the amount is positive and the checking account has sufficient funds
  void TransferToSavings(double amt) {
    if (amt > 0 && checkingAccountBalance >= amt)
    {
      checkingAccountBalance -= amt;
      savingsAccountBalance += amt;
    }
  }
};