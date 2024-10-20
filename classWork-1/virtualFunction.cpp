#include<bits/stdc++.h>

using namespace std;

class base{
    public:
    virtual void print(){
    cout << "Hello from base class\n";
    }
};

class derived : public base{
    public:
    void print(){
    cout << "Hello from derived class\n";
    }
};

int main(){
    base *d = new derived();
    d -> print();
    return 0;
}