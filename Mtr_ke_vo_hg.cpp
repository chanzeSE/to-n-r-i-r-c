#include <iostream>
#include <fstream>
#define N 1000
using namespace std;
int n,a[N][N];
bool songsong(int n, int a[][N]){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (a[i][j]>=2&&i!=j) return true;
        }
    }
    return false;
}
bool vong(int n, int a[][N]){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (a[i][j]>=2&&i==j) return true;
        }
    }
    return false;
}
bool dinhtreo(int n, int a[][N]){
    for (int i=0;i<n;i++){
        int bac=0;
        for (int j=0;j<n;j++) bac+=a[i][j];
        if (bac==1) return true;
    }
    return false;
}
bool dinhcolap(int n, int a[][N]){
    for (int i=0;i<n;i++){
        int bac=0;
        for (int j=0;j<n;j++) bac+=a[i][j];
        if (bac==0) return true;
    }
    return false;
}
int main(){
    ifstream inp("Inp");
    if (!inp.is_open()) {
        cout << "Khong mo duoc file\n";
        return 0;
    }
    cout << "Mo file thanh cong\n";
    inp >> n;
    cout << n<< endl;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            inp>>a[i][j];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    inp.close();
    cout << "Canh song song:";
    if (songsong(n,a)) cout << "Co \n";
    else cout << "khong \n";
    cout << "Vong:";
    if (vong(n,a)) cout << "Co \n";
    else cout << "Khong \n";
    cout << "Dinh treo:";
    if (dinhtreo(n,a)) cout << "Co \n";
    else cout << "Khong \n";
    cout << "Dinh co lap:";
    if (dinhcolap(n,a)) cout << "Co \n";
    else cout << "Khong \n";
}
