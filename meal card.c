#include<stdio.h>
int main()
{
    int n,w[1000]={},c[1000]={},v,i,V,sum=0,max=0,j=0,f[1000]={};
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        c[i]=w[i];
        if(w[i]>max)
        {
            max=w[i];
            j=i;
        }
        sum+=w[i];
    }
    scanf("%d",&V);
    if((sum-max)<(V-5))
    {
        printf("%d",V-sum);
        return 0;
    }
    V=V-5;
    for(i=1;i<n;i++)
    {
        if(i==j)continue;
        for(v=V;v>=0;v--)
            if(v<c[i]) break;
            else f[v]=f[v]>f[v-c[i]]+w[i]?f[v]:f[v-c[i]]+w[i];
    }
    printf("%d",V-f[V]+5-max);
}
