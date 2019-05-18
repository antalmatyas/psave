#include <iostream>

using namespace std;
int kozos( int a, int b)
{
     int kosz = 0;
     for (int i = 1 ; i <= a ; i++)
     {
         if (a%i == 0 && b%i == 0)
         {
             kosz++;
         }
     }

     return kosz;
}

int main()
{
    cout << kozos(4, 6) << endl;
    cout << kozos(7, 8) <<endl;
    cout << kozos(12, 18) << endl;
    return 0;
}
