#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int a[] = {5,6,6,7,10,11};
    int n;
    n = count(a,a+6,6);
    cout << n << endl;
    return 0;
}