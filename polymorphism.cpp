#include<bits/stdc++.h>
using namespace std;

class Vehicle{
    public:
    string name;
    virtual void drive() = 0;
};

class car : public Vehicle{
    public:
    void drive(){
        cout << "car is driving\n";
    }
};

class jeep : public Vehicle{
    public:
    void drive(){
        cout << "jeep is driving\n";
    }
};

class bike : public Vehicle{
    public:
    void drive(){
        cout << "bike is driving\n";
    }
};

int main(){
    Vehicle *v[3];

    v[0] = new car();
    v[1] = new jeep();
    v[2] = new bike();

    for(int i=0; i<3; i++){
        v[i]->drive();
    }

return 0;
}