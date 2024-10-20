#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {10,12,14,17,50,20,25};
    int *ptr;
    ptr = find(a,a+7, 20);
    cout << ptr-a << endl;
    return 0;
}