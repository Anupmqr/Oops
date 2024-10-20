#include<bits/stdc++.h>
using namespace std;

class Equilateral{
    float a;
    float area;
    float perimeter;
    public:
    void set(int length){
        a = length;
        area = (1.73 * a * a)/4;
        perimeter = 3*a;
    }

    friend class Homework;
};

class Homework{
    public:
    void display(Equilateral obj){
        cout << obj.area << endl;
        cout << obj.perimeter << endl; 
    }
};

int main(){
    Equilateral obj;
    obj.set(3);

    Homework obj1;
    obj1.display(obj);
    return 0;
}

