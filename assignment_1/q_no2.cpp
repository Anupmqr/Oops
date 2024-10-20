#include <iostream>

using namespace std;

int main()
{
    int marks;
    cout << "Enter marks of a student (0-100):\n";
    cin >> marks;

    switch (marks / 10) {
        case 10:
        case 9:
            cout << "Grade of student is O (Outstanding)\n";
            break;

        case 8:
            cout << "Grade of student is A+ (Excellent)\n";
            break;

        case 7:
            cout << "Grade of student is A (Very Good)\n";
            break;

        case 6:
            cout << "Grade of student is B+ (Good)\n";
            break;

        case 5:
            cout << "Grade of student is B (Average)\n";
            break;

        case 4:
            cout << "Grade of student is P (Pass)\n";
            break;

        default:
            cout << "Grade of student is F (Fail)\n";
    }

    return 0;
}
