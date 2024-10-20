#include<iostream>
using namespace std;

void Print(int n){
    if(n==1){
        cout << 1 << " ";
        return;
    }

    Print(n-1);
    cout << n << " ";
    Print(n-1);
}

int main(){
    int n = 4;
    Print(n);
    cout << endl;
    return 0;
}