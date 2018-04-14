#include<stdio.h>
void Tarjan(int w)
{
    int i,x;
    for(i=0;i<number[w];i++)
    {
        if(v[w][i]!=0)
            Dfd(v[w][i]);
        else return;
        find[v[w][i]]=find[w];
        vis[v[w][i]]=1;
    }
    for(i=0;i<num[w];i++)
        if(vis[search[w][i]])
        {
            x=search[w][i];
            while(vis[f[x]])
                x=f[x];
            LCA[s][search[w][i]]=LCA[search[w][i]][s]=x;
        }

}
int str[1000]={},z=0,dep[1000]={},count=0,flag[1000]={},local[1000]={},is[1000]={};
void RMQ(int w)
{
    int i,x;
    str[count]=w;
    dep[w]=z;
    if(!flag[w])
    {
        flag[w]=1;
        local[w]=count;
    }
    for(i=0;i<number[w];i++)
    {
        if(v[w][i]!=0)
        {
            z++;
            count++;
            is[w]=1;
            RMQ(v[w][i]);
        }
    }
    if(is[w])
        str[count]=w;
    z--;
    return;
}
int find(int u,int v)
{
    int i,j,k,min=INT_MAX;
    j=local[u]>local[v]?local[v]:local[u];
    k=local[u]<local[v]?local[v]:local[u]
    for(i=j+1;i<k;i++)
    {
        if(min<dep[str[i]]) min=dep[str[i]]);
    }
    return min;
}
int f[1000]={},vis[1000]={},v[1000][2]={},flag[1000]={},number[1000]={},LCA[1000][1000]={};
int main()
{
    int n,m,i,k,v1,v2,search[1000][1000]={},num[1000]={},a,b;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&v1,&v2);
        v[v1][number[v1]]=v2;
        number[v1]++;
        v[v2][number[v2]]=v1;
        number[v2s]++;
    }
    for(i=1;i<=n;i++)
        f[i]=i;
    for(i=0;i<k;i++)
    {
        scanf("%d%d",&a,&b)
        search[a][num[a]]=b;
        search[b][num[b]]=a;
        num[a]++;
        num[b]++;
    }
}
