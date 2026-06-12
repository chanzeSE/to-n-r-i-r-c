#include <iostream>
#include <fstream>
#define N 1000
using namespace std;
int n,m, a[N][N],k;
bool ss_nguoc_huong(){
    int dem=0;
    for (int c1=0;c1<m-1;c1++){
        for (int c2=c1+1;c2<m;c2++){
            bool ok=true;
            for(int i=0;i<n;i++){
                if (a[i][c1]+a[i][c2]!=0) {
                    ok=false;
                    break;
                }
            }
            if (ok) return true;
        }
    }
    return false;
}
bool ss_cung_huong(){
    int dem=0;
    for (int c1=0;c1<m-1;c1++){
        for (int c2=c1+1;c2<m;c2++){
            bool ok=true;
            for(int i=0;i<n;i++){
                if (a[i][c1]!=a[i][c2]) {
                    ok=false;
                    break;
                }
            }
            if (ok) return true;
        }
    }
    return false;
}
void bac(){
    int bac_trong=0;
    int bac_ngoai=0;
    for (int j=0;j<m;j++){
        if (a[k][j]==0) continue;
        int dem1=0;
        for (int i=0;i<n;i++) {if (a[i][j]!=0) dem1++;}
        if (dem1==1) {
            bac_trong++;
            bac_ngoai++;
        }
        else {
            if (a[k][j]==1) bac_ngoai++;
            else bac_trong++;
        }
    }
    cout << "Nua bac trong = "<< bac_trong<< ", nua bac ngoai="<< bac_ngoai<< endl;
}
int main(){
    fstream file("Matrlth", ios::in);
    file >> n >> m >> k;
    for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                file >> a[i][j];
            }
    }
    file.close();
    if (ss_nguoc_huong()) cout << "yes"<<endl;
    else cout << "no"<<endl;
    if (ss_cung_huong()) cout << "yes"<<endl;
    else cout << "no"<<endl;
    bac();
}
