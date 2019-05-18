#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream f("szorzotabla.txt");
    for (int i = 1; i<=10; i++)

    {
        for(int j = 1; j <=10; j ++)
        {
            if (j*i >= 10)
            {
                f <<"  "<<i*j;
            }
            else if (j*i >= 100)
            {
                f <<" "<<i*j;
            }
            else
            {
                f <<"   "<<i*j;
            }
        }
         f <<endl;
    }
    f.close();
    return 0;
}
