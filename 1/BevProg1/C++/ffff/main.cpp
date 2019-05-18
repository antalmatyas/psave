#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;


void randomgeneral(string fname, int mennyi){
   ofstream fa("fa.txt");
   int a =0;
   for (int i=0; i<1000; i++){
    a+= rand() %10;
    fa <<a<< " ";
   }
   fa.close();
}
int main()
{
 randomgeneral("fa.txt", 1000);
 randomgeneral("fb.txt", 1000);

    return 0;
}
