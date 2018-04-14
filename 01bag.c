#include<stdio.h>
int main()
{
    int i,v,N,V,f[1000]={},c[1000],w[1000];
    scanf("%d%d",&N,&V);
    for(i=1;i<=N;i++)
    {
        scanf("%d%d",&c[i],&w[i]);
    }
    for(i=1;i<=N;i++)
        for(v=V;v>=0;v--)//逆序，防止刚更新的值被同一i循环的其他值所利用
            if(v-c[i]<0) continue;
            else
            f[v]=f[v]>f[v-c[i]]+w[i]?f[v]:f[v-c[i]]+w[i];//即目前方案好还是选入此物品（用能选入此物品重量的方案来选此物品）
    printf("%d",f[v]);
}
