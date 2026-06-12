#include <iostream>
#include <algorithm>
using namespace std;
void xuat( int a[],int b[],int n){
    for (int i=0;i<n;i++){
        cout << a[b[i]] << " ";
    }
    cout << endl;
}
// code theo sinh tập con theo thứ tự độ dài nhưng dùng k phần tử
// sinh chỉnh hợp : sinh tổ hợp kết hợp sinh hoán vị
int main (){
    int n,m;
    cin >> n >> m;
    int a[n];
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    int b[m];
    for (int i=0;i<m;i++){
        b[i]=i;
    }
    do{
        int i=m-1;
        xuat(a,b,m);
        while (i>=0&&b[i]==n-m+i) i--;
        if (i<0) break;
        b[i]++;
        for (int j=i+1;j<m ;j++){
            b[j]=b[j-1]+1;
            }
    }while(true);
}
