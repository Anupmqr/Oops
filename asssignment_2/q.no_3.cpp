// finding the student grade using functions, array of objects with class and object

#include<iostream>

using namespace std;

class grade{
    public:
    int n;
    int a[100];

    void result(int a[],int n){
        int marks = 0;
        for(int i=0; i<n; i++){
            marks = marks + a[i];
        }
         switch (marks / (n * 10)) {
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

    }
};

int main()
{
    grade obj;
    cout << "enter total no. of subjects: ";
    cin >> obj.n;

    for(int i=0; i<obj.n; i++){
    cout << "enter marks of subject " << i+1 << " : ";
    cin >> obj.a[i];
    }

    obj.result(obj.a,obj.n);

    return 0;
}