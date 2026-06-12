#include <iostream>
using namespace std;
void xuat(int a[], int n){
    for (int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

bool lientiep(int b[], int i) {
    for (int k = 0; k < i - 1; k++) {
        if (b[k+1] != b[k] + 1) return false;
    }
    return true;
}
bool tangdan(int a[],int b[], int n){
    for (int i=0;i<n-1;i++){
        if (a[b[i]]>=a[b[i+1]]) return false;
    }
    return true;
}
void daycon(int a[], int n){
    bool ok=false;
    int b_size=0;
    int b_arr[100];
    for (int i=n;i>0;i--){
        int b[i];
        for (int j=0;j<i;j++){
            b[j]=j;
        }
        do{
            if (tangdan(a,b,i)&&lientiep(b,i)){
                ok=true;
                b_size=i;
                for (int k=0;k<i;k++){
                    b_arr[k]=a[b[k]];
                    }
                xuat(b_arr,b_size);
                return;
            }
            int j=i-1;
            while (j>=0&&b[j]==n-i+j)j--;
            if (j<0) break;
            b[j]++;
            for (int k=j+1;k<i;k++){
                b[k]=b[k-1]+1;
            }
        }while (true);
    }

}
int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    daycon(a,n);
}
