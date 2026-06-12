#include<stdio.h>
#include<stdbool.h>
int main(){
    bool p,q,r,e;
    int c;
    scanf("%d", &c);
    p=c;
    scanf("%d", &c);
    q=c;
    scanf("%d", &c);
    r=c;
    printf("%d ", (((!p||q)&&r)&&1));
    printf("%d ", (((!p||q)&&r)||0));
    /*printf("%d", (!p||q)&&r);*/
    /*printf("%d %d %d",p,q,r);*/
}
