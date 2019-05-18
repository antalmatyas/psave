#include <iostream>
#include <cmath>

using namespace std;

struct coord
{
int x;
int y;
};

int main()
{
    coord a;
    coord b;
    cin >> a.x;
    cin >> a.y;
    cin >> b.x;
    cin >> b.y;
    coord c;
    c.x = abs(a.x - b.x);
    c.y = abs(a.y - b.y);
    cout << sqrt(pow(c.x,2)+pow(c.y,2));
    return 0;
}
