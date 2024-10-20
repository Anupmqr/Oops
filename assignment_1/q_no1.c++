#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number != 0) {
        if (number > 0) {
            cout << "Positive number" << endl;
        } 
        else {
            cout << "Negative number" << endl;
        }
    } 
    else {
        cout << "Number is zero" << endl;
    }

    return 0;
}
