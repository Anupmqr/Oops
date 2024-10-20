#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int a[] = {7,6,2,7,3,7};
    sort(a,a+6);
    for(int i=0; i<6; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}