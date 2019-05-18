#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ifstream f("a.txt");
    if (!f.good() )
    {
        cerr << "Nem sikerult megnyitni a fajlt" << endl;
        return(1);
    }
    string a;
    string b;

getline(f,a);
while (f.good())
{
    if (a.length()>b.length())
    {
        b=a;
    }
    getline(f,a);
}
cout << b;

    return 0;
}
