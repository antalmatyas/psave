#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1({0,0,0});
    vector<int> v2({0,0,0});
    cout << "Add meg az elso vektor 1. koordinatajat:" << endl;
    cin >> v1[0];
    cout << "Add meg az elso vektor 2. koordinatajat:" << endl;
    cin >> v1[1];
    cout << "Add meg az elso vektor 3. koordinatajat:" << endl;
    cin >> v1[2];

    cout << "Add meg az masodik vektor 1. koordinatajat:" << endl;
    cin >> v2[0];
    cout << "Add meg az masodik vektor 2. koordinatajat:" << endl;
    cin >> v2[1];
    cout << "Add meg az masodik vektor 3. koordinatajat:" << endl;
    cin >> v2[2];

    cout << "A ket vektor vektorialis szorzasanak eredmenye: " <<
    v1[1]*v2[2]-v1[2]*v2[1] << " ; "
    << v1[2]*v2[0]-v1[0]*v2[2] << " ; "
    << v1[0]*v2[1]-v1[1]*v2[0];
    return 0;
}
