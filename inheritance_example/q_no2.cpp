#include<bits/stdc++.h>
using namespace std;

class sales {
private:
    float salesData[3];  

public:
    void getdata() {
        for (int i = 0; i < 3; i++) {
            cout << "Enter sales for month " << i + 1 << ": ";
            cin >> salesData[i];
        }
    }

    void putdata() {
        for (int i = 0; i < 3; i++) {
            cout << "Sales for month " << i + 1 << ": " << salesData[i] << endl;
        }
    }
};

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

class book : public publication, public sales{
    private:
    int pageCount;

    public:
    void getdata(){
        publication::getdata();
        sales::getdata();
        cout << "Enter the no. of page: ";
        cin >> pageCount;
    }
    void putdata(){
        publication::putdata();
        sales::putdata();
        cout << "Total no. of pages: " << pageCount << endl;
    }
};

class tape:public publication, public sales{
    private:
    float playTime;

    public:
    void getdata(){
    publication::getdata();
    sales::getdata();
    cout << "Enter a playing time in minutes: ";
    cin >> playTime;
    }

    void putdata(){
        publication::putdata();
        sales::putdata();
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