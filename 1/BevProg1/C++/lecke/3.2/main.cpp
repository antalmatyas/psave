#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int o;
    o = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        if(n % i == 0)
        {
            o = o+i;
        }
    }
    cout << o;
    return 0;
}
