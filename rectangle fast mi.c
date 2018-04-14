#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define N 100000000
struct Matrix {
    long long z[2][2];//用到值时同样需要赋初值
}e,one;
struct Matrix multiply(struct Matrix x,struct Matrix y)
{
    long long i,j,k;
    struct Matrix ans;
    ans=one;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            for(k=0;k<2;k++)
                ans.z[i][j]=x.z[i][k]*y.z[k][j]+ans.z[i][j];
                 for(i=0;i<2;i++)
    return ans;
}
struct Matrix kuaisumi(struct Matrix x, unsigned long long y)
{
    int i,j;
    struct Matrix a;
    if(!y) return e;
    a= kuaisumi(x, y / 2);
    if(y % 2 == 0) return multiply(a,a);
    else return multiply(multiply(a,a),x);
}
int main()
{
    struct Matrix fi,fn,ans;
    long long i,j,n,m;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<2;i++) e.z[i][i]=1;
    fi.z[0][0]=2;
    fi.z[0][1]=1;
    fi.z[1][0]=1;
    fi.z[1][1]=0;
    one.z[0][0]=0;
    one.z[0][1]=0;
    one.z[1][0]=0;
    one.z[1][1]=0;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            fn.z[i][j]=fi.z[i][j]+e.z[i][j];
    ans=kuaisumi(fn,n);
    printf("%lld ",(ans.z[0][0]*ans.z[1][1]-ans.z[0][1]*ans.z[1][0])%m);
}
