    #include <iostream>
    #include <vector>

    using namespace std;

    hany(vector<double> v, double ez)
    {
      int o=0;
      for (int i = 0 ; i < v.size() ; i++)
      {
          if (v[i] == ez)
          {
              o++;
          }
      }
      return o;
    }

    int main()
    {
        vector<double> v({1,6,3,4,11,4,0});
        cout << hany(v,4) << endl;
        return 0;
    }
