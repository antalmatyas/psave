#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a;
    double b;
    cout << fixed;
    cin >> a;
    cin >> b;
    cout << setprecision(1) << b-a+b << endl;
    return 0;
}
