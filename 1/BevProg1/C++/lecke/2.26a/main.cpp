#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, i;
    cin >> n;
    i = 2;
    while(n != 1 && i <= sqrt(n))
    {
        if(n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
        else
        {
            i++;
        }
    }
    cout << n;
    return 0;
}
