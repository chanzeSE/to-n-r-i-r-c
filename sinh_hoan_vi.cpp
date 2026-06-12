#include <iostream>
#include <algorithm>
using namespace std;
void xuat(int a[],int n){
    for (inta i=0;i<n;i++){
        cout << a[i]<< " ";
    }
    cout <<endl;
}
void daonguoc(int a[], int x, int y){
    while (x<y){
        swap(a[x],a[y]);
        x++;
        y--;
    }
}
void sinhoanvi(int a[], int n){
    do{
        xuat(a,n);
        int i=n-2;
        while (i>=0&&a[i]>a[i+1]) i--;
        if(i<0) break;
        int j=n-1;
        while (j>=0&&a[j]<a[i]) j--;
        swap(a[i],a[j]);
        daonguoc(a,i+1,n-1);
    }while (true);
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    cout << "Hoan vi n:"<< endl;
    sinhoanvi(a,n);
}
