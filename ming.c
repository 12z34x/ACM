#include<stdio.h>
#define N 10000
long long kuaisumi(long long x, unsigned long long y)
{
    long long a;
    if(!y) return 1;
    a= kuaisumi(x, y / 2);
    if(y % 2 == 0) return (a * a);
    else return (a * a * x);
}
int main()
{
    long long a[N],b[N],t,k;
    long i,n;
    scanf("%ld %lld %lld",&n,&t,&k);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    k=kuaisumi(k,t);
    t%=n;
    for(i=0;i<n;i++)
    {
        if(i<t)
        b[i]=a[i-t+n]*k;
        else b[i]=a[i-t]*k;
    }
    for(i=0;i<n;i++)
    {
        printf("%lld ",b[i]%(1000000000+7));
    }
}
