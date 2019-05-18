#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Hozzavalo
{
    float mennyi;
    string nev;
};

Hozzavalo olvas(ifstream &f)
{
Hozzavalo eredm;
char kuka;
f >> eredm.mennyi >> kuka;
getline(f, eredm.nev);
return eredm;
}

int main()
{
    ifstream f("recept.txt");
    if (!f.good())
    {
        cerr << "Nincs meg a file!" << endl;
        exit(1);
    }
    Hozzavalo hv = olvas(f);
    Hozzavalo lt;
    lt.mennyi = 0;
    lt.nev = "...";
    int kme = 0;
    string melyik;
    cout << "Add meg, melyik hazzavalo erdekel: " << endl;
    getline(cin, melyik);


    while(f.good())
    {
        if (hv.mennyi > lt.mennyi)
            {
                lt = hv;
            }
        if (hv.mennyi < 1)
        {
            kme++;
        }
        if (hv.nev == melyik)
        {
            cout << "Ebbõl ennyi kell: " << hv.mennyi << endl;
        }
            cout << hv.mennyi << " " << hv.nev << endl;
            hv = olvas(f);

    }
    cout << "Legtobb: " << lt.nev << endl;
    return 0;
}
