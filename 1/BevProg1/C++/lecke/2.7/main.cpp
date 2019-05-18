#include <iostream>

using namespace std;

int main()
{
    int a;
    int b;
    int e;
    int n;
    bool w;
    w = true;
    a = 0;
    b = 1;
    e = 1;
    cin >> n;
    if(n < 1)
    {
        cout << "Az elso termeszetes szam az 1!";
    }
    else if(n == 1)
    {
        e = 0;
    }
    else if(n == 2)
    {
        e = 1;
    }
    for(int i = 2 ; i < n ; i++)
    {
        e = a+b;
        if(w = true)
        {
            w = false;
            a = e;
        }
        else
        {
            w = true;
            b = e;
        }
    }
    cout << e;
    return 0;
}
