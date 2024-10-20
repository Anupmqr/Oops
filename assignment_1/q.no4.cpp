#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name;
    int roll_no;
    string department;
};

int main() {
    int n;
    cout << "Enter the no. of students:\n";
    cin >> n;

    vector<Student> m(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter details for student " << i + 1 << ":\n";

        cout << "Name: ";
        cin.ignore();
        getline(cin, m[i].name);

        cout << "Roll No: ";
        cin >> m[i].roll_no;

        cout << "Department: ";
        cin.ignore();
        getline(cin, m[i].department);

        cout << endl;
    }

    cout << "-------------Student Details:----------\n";
    for (int i = 0; i < n; i++) {
        cout << "   Student " << i + 1 << ":\n";
        cout << "   Name: " << m[i].name << endl;
        cout << "   Roll No: " << m[i].roll_no << endl;
        cout << "   Department: " << m[i].department << endl;
        cout << endl;
    }

    return 0;
}
