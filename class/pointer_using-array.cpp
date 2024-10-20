#include<iostream>
using namespace std;

int main()
{
    int a[3];
    int *p[3];
    for(int i=0; i<3; i++)
    {
        cin >> a[i];
    }

    for(int i=0; i<3; i++)
    {
        p[i] = &a[i];
    }

    for(int i=0; i<3; i++)
    {
        cout << *p[i] << endl;
    }

return 0;

}