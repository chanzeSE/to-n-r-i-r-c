#include <iostream>
#include <fstream>
#define N 1000
using namespace std;
int n, a[N][N],k;
bool ss_nguoc_huong(){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i!=j && a[i][j]>0 && a[j][i]>0) return true;
        }
    }
    return false;
}
bool ss_cung_huong(){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (i!=j && a[i][j]>=2) return true;
        }
    }
    return false;
}
void bac(){
    int bac_trong=0;
    int bac_ngoai=0;
    for (int i=0;i<n;i++){
        bac_trong+=a[i][k];
        bac_ngoai+=a[k][i];
    }
    cout << "Nua bac trong = "<< bac_trong<< ", nua bac ngoai="<< bac_ngoai<< endl;
}
int main(){
    fstream file("Matr", ios::in);
    file >> n;
    for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                file >> a[i][j];
            }
    }
    file >>k;
    file.close();
    if (ss_nguoc_huong()) cout << "yes"<<endl;
    else cout << "no"<<endl;
    if (ss_cung_huong()) cout << "yes"<<endl;
    else cout << "no"<<endl;
    bac();
}
