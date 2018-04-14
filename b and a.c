#include<stdio.h>
#include<stdlib.h>
long long x,y;
long long exGcd(long long a,long long b)
{
    long long r,t;
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    r=exGcd(b,a%b);
    t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
int main()
{
    long long B,n;
    scanf("%lld%lld",&n,&B);
    if(exGcd(B,9973)==1) x=(x%9973+9973)%9973;
    else x=-1;
    printf("%lld",(x*n)%9973);
}
