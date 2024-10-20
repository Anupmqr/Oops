#include<bits/stdc++.h>
using namespace std;

class publication{
    private:
    string title;
    float price;

    public:
    void getdata(){
        cout << "Enter the name of book: ";
        cin >> title;
        cout << "Enter the price of book: ";
        cin >> price;
    }
    void putdata(){
        cout << "Book: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class book : public publication{
    private:
    int pageCount;

    public:
    void getdata(){
        publication::getdata();
        cout << "Enter the no. of page: ";
        cin >> pageCount;
    }
    void putdata(){
        publication::putdata();
        cout << "Total no. of pages: " << pageCount << endl;
    }
};

class tape:public publication{
    private:
    float playTime;

    public:
    void getdata(){
    publication::getdata();
    cout << "Enter a playing time in minutes: ";
    cin >> playTime;
    }

    void putdata(){
        publication::putdata();
        cout << "Playing time: " << playTime << endl;
    }
};

int main(){
    book obj1;
    tape obj2;
    cout << "Enter book details: " << endl;
    obj1.getdata();
    cout << "Enter tape details: " << endl;
    obj2.getdata();
    cout << "Book details: " << endl;
    obj1.putdata();
    cout << "Tape details: " << endl;
    obj2.putdata();
    return 0;
}