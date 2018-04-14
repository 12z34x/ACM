#include<stdio.h>
#include<math.h>
int main()
{
    long long M,N;
    double k;
    scanf("%lld%lld",&M,&N);
    k=pow(M,N-2);
    printf("%lld",(long long)k);
}
