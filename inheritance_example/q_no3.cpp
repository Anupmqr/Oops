#include<bits/stdc++.h>
using namespace std;

enum DiskType { CD, DVD };

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

    float calculateTotalSales() {
        float totalSales = 0.0;
        for (int i = 0; i < 3; i++) {
            totalSales += salesData[i];
        }
        return totalSales;
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

class Disk : public publication, public sales {
private:
    DiskType diskType;

public:
    void getdata() {
        publication::getdata();
        sales::getdata();
        char type;
        cout << "Enter the disk type (c for CD, d for DVD): ";
        cin >> type;
        if (type == 'c' || type == 'C') {
            diskType = CD;
        } else if (type == 'd' || type == 'D') {
            diskType = DVD;
        } else {
            cout << "Invalid disk type, defaulting to CD." << endl;
            diskType = CD;
        }
    }

    void putdata() {
        publication::putdata();
        sales::putdata();
        cout << "Disk Type: " << (diskType == CD ? "CD" : "DVD") << endl;
    }
};

int main() {
    book obj1;
    tape obj2;
    Disk disk;

    cout << "Enter book details:" << endl;
    obj1.getdata();

    cout << "\nEnter tape details:" << endl;
    obj2.getdata();

    cout << "\nEnter disk details:" << endl;
    disk.getdata();

    cout << "\nBook details:" << endl;
    obj1.putdata();

    cout << "\nTape details:" << endl;
    obj2.putdata();

    cout << "\nDisk details:" << endl;
    disk.putdata();

    return 0;
}