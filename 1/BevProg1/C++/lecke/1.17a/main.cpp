#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    string a;
    cin >> a;
    int b = a.length();
    if(tolower(a[0]) == a[b-1] || toupper(a[0]) == a[b-1])
    {
        cout << "igaz" << endl;
    }
    else
    {
        cout << "hamis" << endl;
    }
    return 0;
}
