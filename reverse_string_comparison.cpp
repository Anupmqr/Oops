#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    // Define the first string, "Hello".
    string s1 = "Hello";

    // Reverse the characters in s1.
    reverse(s1.begin(), s1.end());

    // Define the second string, "olleH".
    string s2 = "olleH";

    // Compare s1 and s2 and store the result in x.
    int x = s1.compare(s2);

    // Check if x is non-zero, indicating that the strings are different.
    if (x)
    {
        cout << "Strings are different" << endl;
    }
    else
    {
        // x is zero, indicating that the strings are the same.
        cout << "Strings are the same" << endl;
    }

    return 0;
}