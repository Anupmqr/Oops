#include<iostream>
using namespace std;

class calculation{
    int area;
    int perimeter;
    public:
    void Print(int l, int b){
        area = l*b;
        perimeter = 2*(l+b);
    }

    friend void result(calculation);
};

void result(calculation obj){
    cout << obj.area << endl; 
    cout << obj.perimeter << endl;
}

int main(){
    calculation obj;
    obj.Print(2,3);
    result(obj);
    return 0;
}