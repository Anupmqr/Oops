// convert farhenheit to celsius using function with class and objects

#include<iostream>
#include<iomanip>
 using namespace std;


class temp{
    public:
    float f;

    void conversion(float c){
        cout << fixed << setprecision(2) << (c-32) * (5.0/9.0) << endl;
    }
};


 int main()
 {
    temp obj;
    cout << "enter the temp in farhenheit: ";
    cin >> obj.f;
    obj.conversion(obj.f);
    return 0;
 }