#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 2;
    cout << "PRIME NO. BETWEEN 1 TO 1000 ARE:\n";
    while (n != 1000)
    {
        int c = 1;
        int x = 0;
        while (c != n + 1)
        {
            if (n % c == 0)
            {
                x++;
            }
            c++;
        }
        if (x == 2)
            cout << n << " ";
        n++;
    }
    return 0;
}
