#include<stdio.h>
int gcd(int a,int b)
{
    int t;
    if(a>b)
    {
        t=a;
        b=a;
        a=t;
    }
    if(b%a==0)
        return a;
    else return(gcd(b%a,a));
}
int main()
{
    int n,m,j,i,num=0;
    scanf("%d%d",&n,&m);
    for(i=n;i<=m;i++)
        for(j=1;j<i;j++)
            if(gcd(j,i)==1) num++;
    printf("%d",num);
}
