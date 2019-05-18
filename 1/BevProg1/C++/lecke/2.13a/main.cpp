#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main()
{
    string a;
    getline (cin, a);
    cout << (char)toupper(a[0]) << ". ";
    int b;
    b = a.length();
    for(int i = 0 ; i < b ; i++)
    {
        if(isspace(a[i]))
        {
            cout << (char)toupper(a[i+1]) << ". ";
        }
    }
    return 0;
}
