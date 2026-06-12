#include <iostream>
#include <iomanip>
using namespace std;
struct bien{
    bool p,q,r,E;
};
int main(){
    bien a[8];
    cout << "|  p  |  q  |  r  |  E  |"<<endl;
    int i=0;
    for (int p=1;p>=0;p--){
        for (int q=1;q>=0;q--){
            for (int r=1;r>=0;r--){
                a[i].p=p;
                a[i].q=q;
                a[i].r=r;
                a[i].E=(!p||q)&&r;
                i++;
            }
        }
    }
    for (int i=0;i<8;i++){
        cout <<"|  "<<a[i].p<<"  |  "<<a[i].q<<"  |  "<<a[i].r<<"  |  "<<a[i].E<<"  |"<<endl;
    }
}
