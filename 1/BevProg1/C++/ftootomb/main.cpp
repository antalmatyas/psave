#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

void beolvas(string filename, vector<int>& v)
{
 ifstream f(filename);
 if (!f.good()) {
    cerr << "hiba" << endl;
    exit(1);
 }
 int x;
    f>> x;
 while(f>>x) {
    v.push_back(x);
    }
}
void beolvas2(ifstream f2(""))
{

}
int main()
{
    int b =
    vector<int>v;
    beolvas("a.txt",v);
    for (int a:v) {
        cout << a<< " ";
        }
    return 0;
}
