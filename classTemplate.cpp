#include<iostream>
using namespace std;

template <typename T>
class Printer{
    T input;

    public:
    Printer(T i){
    input = i;
    }

    void display(){
        cout << input << endl;
    }
};

int main(){
    Printer <double>obj1(2.59);
    Printer <char>obj2('g');
    obj1.display();
    obj2.display();
    return 0;
}