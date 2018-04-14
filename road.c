#include<stdio.h>
void init(int n)
{
    for(i=0;i<n;i++)
        {parent[i]=-1;rank[i]=1;}
}
void union(int R1,int R2)
{
    int r1=find(R1),r2=find(R2);
    if (r1==r2)return 0;
    else if(rank[r1]>=rank[r2])
    {
        parent[r2]=r1;
        rank[r1]+=rank[r2];
    }
    else
    {
        parent[r1]=r2;
        rank[r2]+=r1;
    }
}
int find(int x)
{
    int s;
    for(s=x;parent[s]>=0;s=parent[s]);
    int tmp;
    while(s!=x)
    {
        tmp=parent[x];
        parent[x]=s;
        x=tmp;
    }
    return s;
}
