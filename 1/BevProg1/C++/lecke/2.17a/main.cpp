#include <iostream>
#include <string>

using namespace std;

int main()
{
    string e;
    getline(cin,e,'(');
    cout << getline(cin,e,')');
    return 0;
}
