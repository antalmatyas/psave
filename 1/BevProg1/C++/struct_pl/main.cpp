#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct coord {
int x;
int y;
};

void fbe (string fnev, vector<coord>& bvec) {
ifstream bef(fnev);
int i, j;
while(bef>>i & bef >> j){
        coord k;
k.x=i;
k.y=j;
    bvec.push_back(k);

}
}

int main()
{
    coord a;
    a.x = 5;
    a.y = 4;
    return 0;
}
