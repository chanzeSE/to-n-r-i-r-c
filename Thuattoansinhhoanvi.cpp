#include <iostream>
using namespace std;
int gt(int n){
    if(n==0) return 1;
    return n*gt(n-1);
}
void hoanvi(vector<int>& s, int i, int n){
    
}
int main(){
    int n;
    cin>>n;
    vector<int> s(n);
    for(int i=0;i<n;i++){
        s[i]=i+1;
    }
    fot (int i=1,i<gt(n)-1,i++){
        hoanvi(s,i,n);
    }
    return 0;
}