#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct szam{int sz, string nev};

szam olvas(fstream &f)
{
    char kuka;
    szam eredm;
    f >> eredm.sz >> kuka;
    getline(f, eredm.nev);
}

int main()
{
    ifstream f("telefonkonyv.txt");
    if(!f.good)
    {
        cout << "Gond van, havver" << endl;
        exit(1);
    }
    szam telefon = olvas(f);
    while(f.good)
    {
        cout << eredm.sz << eredm.nev <<
    }
    return 0;
}
