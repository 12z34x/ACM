#include<stdio.h>
#include<stdlib.h>
int parent[1000]={};
int rank[1000]={};
void init(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        parent[i]=i;//一共两种版本
        rank[i]=1;
    }
}
int find(int x)
{
   while(parent[x]!=x)
    x=parent[x];
   return x;
}
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
        rank[y]+=rank[x];
    }
}
int main()
{
    int n,m,v1,v2,i,j,flag[1000]={},num=0,number[1000]={};
    scanf("%d%d",&n,&m);
    init(n);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&v1,&v2);
        unit(v1,v2);
    }
    for(i=1;i<=n;i++)//认为顶点下标从1开始
    {
        if(flag[i]==1)continue;
        num++;
        number[num]=1;
        flag[i]=1;
        for(j=1;j<=n;j++)
            if(find(i)==find(j))
            {
                flag[j]=1;
                number[num]++;
            }

    }
    printf("%d",num);//num-1为至少还需要建造路的个数
    for(i=0;i<num;i++)
        printf("%d",number[i+1]);
}
