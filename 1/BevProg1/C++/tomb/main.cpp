#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    vector< vector<int>> m(10, vector<int>(5,42));
    for (size_t i=0; i < m.size(); i++)
    {
        for(size_t j = 0; j < m[i].size();j++)
        {
            m.at(i).at(j) = (i==7) ? 5 : rand() % 5+1;
            cout<<m.at(i).at(j)<<" ";
        }
    cout<<endl;
    }
return.0;



    int o;
    vector<int> v(1000);
    for (size_t i = 0 ; i < v.size() ; i++)
    {
        v[i] = rand() % 100;
    }
    for(int a : v)
    {
        cout << a << " ";
        o += a;
    }
    cout << float(o) / v.size();
    return 0;
}
