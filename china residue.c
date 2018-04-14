#include<stdio.h>
#include<math.h>
int niyuan(int M, int  N)
{
    double k;
    k=pow(M,N-2);
    return (int)k;
}
int main()
{
    int N,i,j,p[100],m[100],M=1,t[100]={},k=0;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        {
            scanf("%d%d",&m[i],&p[i]);
            M*=m[i];
        }
    for(i=0;i<N;i++)
    {
        t[i]=niyuan((M/m[i]),m[i]);
        k+=p[i]*t[i]*(M/m[i]);
    }
    printf("%d",k%M);
}
