#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a;
    cin >> a;
    int b;
    int c;
    cin >> b;
    // b mindig nagyobb mint a
    if(a>b)
    {
       c = a;
       a = b;
       b = c;

    }
    for (int  i = 1 ; i <= a ; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            cout << i << " ";
        }
    }
    return 0;
}
