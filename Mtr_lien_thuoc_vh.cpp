#include <iostream>
#include <fstream>
#define N 1000
using namespace std;
int n,m, a[N][N],bac[N];
int tinh_bac(int k){
    int b=0;
    for (int j=0;j<m;j++){
        if (a[k][j]==0) continue;
        int dem=0;
        for (int i=0;i<n;i++) if (a[i][j]==1) dem++;
        if (dem==1) b+=2;
        else b+=1;
    }
    return b;
}
void Bac(){
    for (int k=0;k<n;k++){
        bac[k]=tinh_bac(k);
    }
}
bool songsong(){
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
bool vong(){
    for (int i=0;i<m;i++){
        int dem=0;
        for (int j=0;j<n;j++){
            if (a[j][i]==1) dem++;
        }
        if (dem==1) return true;
    }
    return false;
}
bool dinhtreo(){
    for (int i=0;i<n;i++){
        if (bac[i]==1) return true;
    }
    return false;
}
bool dinhcolap(){
    for (int i=0;i<n;i++){
        if (bac[i]==0) return true;
    }
    return false;
}
int main(){
    fstream file("Matrlth", ios::in);
    file >> n >> m;
    for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                file >> a[i][j];
            }
    }
    file.close();
    Bac();
    cout << "Song song:";
    if(songsong()) cout << "Yes";
    else cout << "No";
    cout <<endl<< "Vong:";
    if(vong()) cout << "Yes";
    else cout << "No";
    cout <<endl<< "Dinhtreo:";
    if(dinhtreo()) cout << "Yes";
    else cout << "No";
    cout <<endl<< "Dinhcolap:";
    if(dinhcolap()) cout << "Yes";
    else cout << "No";

}
