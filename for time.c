#include<stdio.h>
long long zuheshu(long long x,long long y)
{
    long long m=1,n=1,i,j;
    for(i=0;i<y;i++)
        m*=(y-i);
    for(i=0;i<y;i++)
        n*=(x-i);
    return n/m;
}
int main()
{
    long long n,m;
    scanf("%lld%lld",&m,&n);
    printf("%lld",zuheshu(n,m));
}
