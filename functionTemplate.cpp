#include<iostream>
using namespace std;

template <typename T>
void Swap(T&a, T&b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    int a= 2, b= 5;
    char x ='x', y='y';

    Swap(a,b);
    cout << a << " " << b << endl; 
    Swap(x,y);
    cout << x << " " << y << endl;
    return 0;
}