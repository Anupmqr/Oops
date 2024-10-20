#include<bits/stdc++.h>

using namespace std;

class sum{
    public:
    int n;
};

int main()
{
    int a;
    int result = 0;
    sum obj;
    cout << "how many number you want to add: ";
    cin >> obj.n;
    for(int i=0; i<obj.n; i++){
        cin >> a;
        result = result + a;
    }
    cout << result << endl;
    return 0;
}