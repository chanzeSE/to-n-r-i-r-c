#include <iostream>
#include <algorithm>
using namespace std;
void xuat(int a[], int b[], int n){
    for (int i=0;i<n;i++){
        cout << a[b[i]] << " ";
    }
    cout << endl;
}
void daonguoc(int a[],int x,int y){
    while(x<y){
        swap (a[x],a[y]);
        x++;
        y--;
    }
}
void hoanvi(int a[],int b[], int n){
    do {
        xuat(a,b,n);
        int i=n-2;
        while (i>=0&&b[i]>=b[i+1]) i--;
        if(i<0) break;
        int j=n-1;
        while (j>=0&&b[j]<b[i]) j--;
        swap(b[i],b[j]);
        daonguoc(b,i+1,n-1);
    }while(true);
}
int main(){
    int n,m;
    cin >> n >>m;
    int a[n];
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    int b[m];
    for (int i=0;i<m;i++){
        b[i]=i;
    }
    do {
        int i=m-1;
        int c[m];
        for (int i=0;i<m;i++){
            c[i]=b[i];
        }
        hoanvi(a,c,m);
        while (i>=0&&b[i]==n-m+i) i--;
        if (i<0) break;
        b[i]++;
        for (int j=i+1;j<m ;j++){
            b[j]=b[j-1]+1;
            }
    }while(true);
}
