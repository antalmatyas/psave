#include <iostream>

using namespace std;

int main()
{
    string a;
    getline(cin, a);
    string b;
    getline(cin, b);
    if(a.substr(0,5) == b.substr(0,5))
    {
        cout << "igaz" << endl;
    }
    else
    {
        cout << "hamis" << endl;
    }
    return 0;
}
