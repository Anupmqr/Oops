#include <bits/stdc++.h>
using namespace std;

class Printer
{
    string _name;
    int _avlpage;

public:
    Printer(string printerName, int n)
    {
        _name = printerName;
        _avlpage = n;
    }

    void Print(string txtDoc)
    {
        int r = txtDoc.length() / 10;
        if (r > _avlpage)
            throw "no page";

        cout << txtDoc << endl;
        _avlpage -= r;
    }
};

int main()
{
    Printer obj("anup", 2);
    try
    {
        obj.Print("hello my name is anup bamrel");
        obj.Print("hello my name is anup bamrel");
        obj.Print("hello my name is anup bamrel");
        obj.Print("hello my name is anup bamrel");
    }
    catch (const char * txte)
    {
        cout << txte;
    }
    return 0;
}
