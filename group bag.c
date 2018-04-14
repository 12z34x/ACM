#include<stdio.h>
int main()
{
    int V,i,n,c[1000][1000]={},k,w[1000][1000]={},j=0,f[1000]={},v;
    scanf("%d%d",&V,&n);
    for(i=0;i<n;i++)
        while(scanf("%d%d",&c[i][j],&w[i][j])!=EOF);
            j++;
    for(i=0;i<n;i++)
        for(v=V;v>=0;v--)
            for(k=0;k<j;k++)
                if(v<c[i][k])continue;
                else f[v]=f[v]>f[v-c[i][k]]+w[i][k]?f[v]:f[v-c[i][k]]+w[i][k];
}
