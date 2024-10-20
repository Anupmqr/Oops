#include<iostream>
using namespace std;

class Complex{
    private:
    int real, img;
    public:
    Complex(){
        real = 0;
        img = 0;
    }
    Complex(int r, int i){
        real = r;
        img = i;
    }

    void print(){
        cout << real << "+" << img << "i" << endl;
    }

    Complex operator *(Complex c){
        Complex temp;
        temp.real = real * c.real - img * c.img;
        temp.img = real*c.img + c.real*img;
        return temp;
    }
};


int main(){
    Complex c1(3,4), c2(5,6);
    Complex c3;

    c3 = c1 * c2;   // c1(a,b) * c2(c,d) = c3(ac-bd,ad+bc)
    c3.print();

    return 0;
}