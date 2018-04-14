#include<stdio.h>
int main()
{
    int V,U,f[1000][1000]={},w[1000],i,a[1000],b[1000],N,v,u;
    scanf("%d%d%d",&N,&V,&U);
    for(i=0;i<=N;i++)
        scanf("%d%d%d",&a[i],&b[i],&w[i])
    for(i=0;i<=N;i++)
        for(v=V;v>=0;v--)
            if(v<a[i]) continue;
            else
                for(u=U;u>=0;u--)
                    if(u<b[i]) continue;
                    else
                        f[v][u]=f[v][u]>f[v-a[i]][u-b[i]+w[i]?f[v][u]:f[v-a[i]][u-b[i]]+w[i];

}
