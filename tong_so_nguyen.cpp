#include <iostream>
#include <algorithm>
using namespace std;
int tong(int a[], int b[], int n){
    int t=0;
    for (int k=0;k<n;k++){
        t+=a[b[k]];
    }
    return t;
}
void xuat(int a[],int n){
    for (int i=0;i<n;i++){
        cout << a[i]<< " ";
    }
    cout << endl;
}
void timmax(int a[], int n, int k){
    int b_size,Max=-10000;
    bool ok=false;
    int b_arr[n];
    for (int i=1;i<=n;i++){
        int b[i];
        for (int j=0;j<i;j++){
            b[j]=j;
        }
        do{
            if (Max<tong(a,b,i)&&tong(a,b,i)<k) {
                b_size=i;
                for(int t=0;t<i;t++){
                    b_arr[t]=a[b[t]];
                }
                Max=tong(a,b,i);
                ok=true;
                }
            int j=i-1;
            while (j>=0&&b[j]==n-i+j) j--;
            if (j<0) break;
            b[j]++;
            for (int t=j+1;t<i;t++){
                b[t]=b[t-1]+1;
            }
        }
        while(true);
    }
    if (ok) {
        xuat(b_arr,b_size);
        cout << "tong la "<<Max;
    }
    else cout << "ERROR!";
}
int main(){
    int n,k;
    cout << "Nhap so nguyen n:";
    cin >> n;
    int a[n];
    cout << "Nhap n so nguyen:"<< endl;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << "Nhap gia tri k:";
    cin >>k;
    timmax(a,n,k);
}
