#include <iostream>

using namespace std;

int main()
{
    string a;
    cin >> a;
    if (toupper(a[0]) == a[0])
    {
        cout << "igaz" << endl;
    }
    else
    {
        cout << "hamis" << endl;
    }
    return 0;
}
