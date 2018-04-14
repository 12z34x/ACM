#include<stdio.h>
void zhiyueshu(int x)
{
    int m,i;
    m=x;
    for(i=2;i*i<=m;i++)
    {
        if(m%i==0)
        {
            p[x][num[x]]=i;
            num[x]++;
        }
        while(m%i==0) m/=i;
    }
    if(m>1)
    {
        p[x][num[x]]=m;
        num[x]++;
    }
}
void computing()
{
    int cnt=num[M];
    for(int i = 1; i < (1<<cnt); i++)//含有M的质约数的所有组合
    {
        int  t = 0 , ret = 1;
        for(int j = 0; j < cnt; j++){
            if(i&(1<<j))//针对不同组合所要用到M的第j个质约数
            {
                t++;
                ret *= P[M][j];//满足公约数是M的一个或多个质约数时，相当于公约数是这些质约数的乘积
            }
        }
        if(t%2 == 0)
            ans -= pow(M/ret , N);//根据容斥原理，单数+，双数-
        else
            ans += pow(M/ret , N);
    }
    printf("%lld\n" , pow(M , N)-ans);
}

int N,M,p[1000][1000]={},num[1000]={},ans=0;
int main()
{
    int i;
    scanf("%d%d",&N,&M);
    for(i=2;i<=N;i++)
        zhiyueshu(i);
}
