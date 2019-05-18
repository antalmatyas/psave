#include <iostream>

using namespace std;

void fv(double& a)
{
    a = 0;
}

int main()
{
    double d;
    d = 1;
    fv( d );
    cout << "eredmeny: " << d << endl;

    return 0;
}
