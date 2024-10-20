// Write a c++ program to find the largest number using dynamic memory allocation

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin  >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int maxNum = arr[0];
    for(int i=1; i<n; i++){
        maxNum = max(maxNum,arr[i]);
    }

    cout << maxNum;
}