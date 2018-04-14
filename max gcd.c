#include<stdio.h>
long long gcd(long long a,long long b)
{
    long long t;
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
    long long N,i,sum=0;
    scanf("%lld",&N);
    for(i=1;i<=N;i++)
        sum+=gcd(i,N);
    printf("%lld",sum);
}
