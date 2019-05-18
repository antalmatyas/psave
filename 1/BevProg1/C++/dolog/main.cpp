#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
srand(time(0));
int a = rand() % 100;
int b = 0;
bool f = false;

while(f == false)
{cin >> b;

if(a == b)
{
    cout << "Kitalaltad!!" << endl;
    f = true;
}
else if ( a > b)
{
    cout << "Ennel nagyobb" << endl;
}
else if (b > a)
{
    cout << "Ennel kisebb" << endl;
}
}
    return 0;
}
