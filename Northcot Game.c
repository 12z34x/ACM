#include<stdio.h>
int main()
{
    int i,num=0,n,m,T[1000]={},J[1000]={};
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&T[i],&J[i]);
        if(T[i]-J[i]>1||T[i]-J[i]<-1)
            num++;
    }
    if(num%2==0) printf("BAD LUCK!");
    else printf("I WIN!");
}
