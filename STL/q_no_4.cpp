#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v;
    
    v.push_back(1);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    
    v[0] = 10;
    v[2] = 20;
    
    for(int i=0; i<4; i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}