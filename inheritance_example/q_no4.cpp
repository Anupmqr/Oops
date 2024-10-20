#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
  string name;
  int acc_no;
  string acc_type;
  float balance;

public:
  Account(string name, int acc_no, string acc_type) {
    this->name = name;
    this->acc_no = acc_no;
    this->acc_type = acc_type;
    balance = 0;
  }

  void deposit(float amount) {
    balance += amount;
    cout << "Deposit successful." << endl;
  }

  void display_balance() {
    cout << "Current balance for account " << acc_no << " is " << balance << "." << endl;
  }
};

class Current_Account : public Account {
private:
  float minimum_balance;
  float service_charge;

public:
  Current_Account(string name, int acc_no) : Account(name, acc_no, "current") {
    minimum_balance = 5000;
    service_charge = 100;
  }

  void withdraw(float amount) {
    if (balance - amount < minimum_balance) {
      cout << "Withdrawal amount is greater than minimum balance. Service charge of " << service_charge << " will be imposed." << endl;
      balance -= service_charge;
    }
    balance -= amount;
    cout << "Withdrawal of " << amount << " successful." << endl;
  }
};

class Savings_Account : public Account {
private:
  float interest_rate;

public:
  Savings_Account(string name, int acc_no) : Account(name, acc_no, "savings") {
    interest_rate = 0.05;
  }

  void compound_interest() {
    float interest = balance * interest_rate;
    balance += interest;
    cout << "Interest deposited." << endl;
  }

  void withdraw(float amount) {
    if (balance - amount < 0) {
      cout << "Withdrawal amount is greater than available balance." << endl;
      return;
    }
    balance -= amount;
    cout << "Withdrawal of " << amount << " successful." << endl;
  }
};

int main() {
  Current_Account c("John Doe", 12345);
  Savings_Account s("Jane Doe", 67890);

  c.deposit(10000);
  c.display_balance();
  c.withdraw(3000);
  c.display_balance();
  c.withdraw(5000);
  c.display_balance();

  s.deposit(5000);
  s.display_balance();
  s.compound_interest();
  s.display_balance();
  s.withdraw(2000);
  s.display_balance();

  return 0;
}