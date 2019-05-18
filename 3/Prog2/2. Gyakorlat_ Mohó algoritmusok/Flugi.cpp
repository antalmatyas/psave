#include <iostream>
#include <vector>

using namespace std;

const vector<int> cimletek={1, 4, 5, };

struct Fiz{
    vector<int>mibolmennyi;
    int hianyzik;
    Fiz(int mennyit): mibolmennyi(cimletek.size(), 0){
        hianyzik=mennyit;
    }
    int osszeg() const{ ///lekérdezõ fv, nem változtatja meg az értékeket, szabad hívni constans típusú Fiz-re is
        int sum=0;
        for(size_t i=0; i<cimletek.size(); ++i){
            sum+=mibolmennyi[i]*cimletek[i];
        }
        return sum;
    }

    int fizet(int cimletindex){
        mibolmennyi[cimletindex]++;
        hianyzik-=cimletek[cimletindex];
    }

    int ermeszam() const{
    int sum=0;
    for(size_t i=0; i<cimletek.size(); i++){
        sum+=mibolmennyi[i];
        }
    }
};

ostream& operator<<(ostream& out, const Fiz& f){
    out<<"[";
    for(size_t i=0; i<cimletek.size(); i++){
            for(int j=0; j<f.mibolmennyi[i]; j++){
                out<<cimletek[i]<<" ";
            }

    }
    out<<" ->"<<f.osszeg()<<" ]";
    return out;
}

void moho (Fiz f){
    for (int c=cimletek.size()-1; c>=0; c--){
        cout<<cimletek[c]<<":"<<endl;
        while (f.hianyzik>cimletek[c]){
            f.fizet(c);
            cout<<f<<endl;
        }
    }
    cout<<f<<endl;
}

void probal (Fiz f) {
    if(f.hianyzik==0){
        cout<<f<<endl;
    }
    else{
        for(size_t i=0; i<cimletek.size(); i++){
            Fiz uj(f);
            uj.fizet(i);
            if(uj.hianyzik>=0){
                probal(uj);
            }
        }
    }



}
int main()
{
    Fiz f(8);
    //moho(f);
    probal(f);
    return 0;
}
