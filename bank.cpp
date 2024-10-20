#include<bits/stdc++.h>
using namespace std;

class account{
    string customer_name;
    string acc_no. ;
    string typeOfAcc;
    public:
    void bankDetail(){
        cout << "enter your name?\n";
        cin >> customer_name;
        cout << "enter your acc_no.\n";
        cin >> acc_no. ;
        cout << "enter the type of account\n";
        cin >> typeOfAcc;
    }
};

class cur_acc : public account{
    double totalAmount;
    double balance;

    public:
    void deposit(){
    cout << "enter the balance to deposit\n";
    cin >> balance;
    totalAmount += balance;
    }

    void display(){
        cout << "Total balance is " << totalAmount << "\n";
    }

    void withdraw(){
        int min_amount = 3000;
        int withdraw_amount;
        cout << "enter amount to withdraw\n";
        cin >> withdraw_amount;
        totalAmount -= amount;
        
    }
};

class sav_acc : public account{
    int balance;
    public:

};

int main(){

}