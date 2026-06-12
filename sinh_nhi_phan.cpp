#include <iostream>
#include <Cmath>
using namespace std;
int dem=0;
void xuat(int a[], int n){
    for (int i=0;i<n;i++){
        cout << a[i]<<" ";
    }
    cout <<endl;
    dem++;
}
void nhiphan(int n){
    int a[n]={0};
    int i;
    do{
        i=n-1;
        while (i>=0&& a[i]==1) a[i--]=0;
        if (i>=0) a[i]=1;
    }
    while (i>=0);
}
int main(){
    int n;
    cout << "Nhap n:";
    cin >> n;
    cout << dem;
    return 0;
}


