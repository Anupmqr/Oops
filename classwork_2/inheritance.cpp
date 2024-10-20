#include<bits/stdc++.h>
//#include<cstdalign>
using namespace std;

// base class (parent class)
class SRM_UNIVERSITY{
    public:
    string id = "AP22110011484";
};

// derived class (child class)
class student : public SRM_UNIVERSITY{
    public:
    string name = "Dijan";
    string department = "B.Tech CSE";
};

int main(){
    student obj;
    cout << obj.id + "\n" + obj.name + "\n" + obj.department << endl;

    return 0;
}