#include<stdio.h>
int main()
{
    int x,y,p,q,k=1;
    scanf("%d %d %d %d",&x,&y,&p,&q);
    if(p==0)
        if(x==0) {printf("0");return 0;}
        else {printf("-1");return 0;}
    else if(p==q)
        if(x==y) {printf("0");return 0;}
        else {printf("-1"); return 0;}
    else while(k*p<x||k*q<y||k*q-y<k*p-x) k++;
    printf("%d",k*q-y);
}
