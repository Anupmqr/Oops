#include<bits/stdc++.h>
using namespace std;

class myexception : public exception{
    public:
    virtual const char* what() const throw(){
        return "Divided by zero exception\n";
    }
};

int main(){
    int a=10, b=0;

    try{
        if(b==0){
            myexception m;
            throw m;
        }
        cout << a/b << endl;
    }
    catch(exception &obj){
        cout << "Exception caught here: " << obj.what();
    }
    return 0;
}