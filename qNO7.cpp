#include<bits/stdc++.h>
using namespace std;

class student{
    string student_name;
    string campus;
    string year_of_entry;
    string stream;
    string branch;
    string roll_no;
    string department;

    public:
    student(string n, string r){
        student_name = n;
        roll_no = r;
        extract_details();
    }

    void extract_details(){
        year_of_entry = "20" + roll_no.substr(2,2);

        if(roll_no[0]=='A' && roll_no[1]=='P')
            campus = "Andhra Pradesh";
        else if(roll_no[0]=='C' && roll_no[1]=='H')
            campus = "Chennai";
        else if(roll_no[0]=='D' && roll_no[1]=='L')
            campus = "Delhi";

        if(roll_no.substr(4,2) == "11")
        branch = "B.tech";
        else if(roll_no.substr(4,2) == "11")
        branch = "M.tech";


        
    }

    void display(){
        cout << "student_name: " << student_name << endl;
        cout << "campus: " << campus <<  endl;
        cout << "year_of_entry: " << year_of_entry << endl;
        // cout << "stream: " << stream << endl;
        // cout << "branch: " << branch << endl;
        cout << "roll_no: " << roll_no << endl;
        //cout << "department: " << department << endl;
    }


};

int main(){
    student obj("Anup","AP18110010324");
    obj.display();
    return 0;
}