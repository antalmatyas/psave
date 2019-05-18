#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a;
    int b;
    int c;
    cin >> a;
    cin >> b;
    cin >> c;
    int s = (a + b + c)/2;
    cout << sqrt(s * (s - a) * (s - b) * (s - c));
    return 0;
}
