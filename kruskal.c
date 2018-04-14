#include<stdio.h>
struct edge
{
    int from;
    int to;
    int rank;
    int flag;
}*e;
void unit(int x,int y)
{
    x=find(x);
    y=find(y);
    if(rank[x]>=rank[y])
    {
        parent[y]=x;
        rank[x]+=rank[y];
    }
    else
    {
        parent[x]=y;
    }
}
int parent[1000]={};
void init(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        parent[i]=-1;//一共两种版本
        rank[i]=1;
    }
}
int find(int x)
{
   while(parent[x]!=-1)
    x=parent[x];
   return x;
}
int v,E;
int main()
{
    int i,j,x,y,z,tmp,min=INT_MAX,n=0;
    scanf("%d%d",&v,&E);
    init(v);
    for(i=1;i<=E;i++)
        scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].rank);
    for(i=1;i<=E-1;i++)
       {
        for(j=i;j<=E-1;j++)
        if(e[j].rank<min)
        {
            min=e[j].rank;
            tmp=j;
        }
        if(tmp!=i)
        {
            x=e[i].from;
            e[tmp].from=e[i].from;
            e[i].from=x;
            y=e[i].to;
            e[tmp].to=e[i].to;
            e[i].to=y;
            z=e[i].rank;
            e[tmp].rank=e[i].rank;
            e[i].rank=z;
        }
       }
    for(i=1;i<=E-1&&n<v-1;i++)
    {
        if(find[e[i].from]!=find[e[i].to])
        {
            e[i].flag=1;
            unit(e[i].from,e[i].to);
            n++;
        }

    }
}
