#include<stdio.h>
#include<stdlib.h>
int parent[1000]={};
int rank[1000]={};//权值
int sum=0,N,D;
int flag[1000]={};
void init(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        parent[i]=i;//一共两种版本
        rank[i]=1;
    }
}
int find(int x)//无权值时的路径压缩
{
    int s;
    s=x;
   while(parent[s]!=s)
    s=parent[s];
    int tmp;
    while(parent[x]!=s)
    {
        tmp=parent[x];
        parent[x]=s;
        x=tmp;
    }
   return s;
}
int findrank(int x) //有权值时的路径更新
{
    int temp;
    if(x == parent[x])
        return x;
    temp = parent[x]; //路径压缩
    parent[x]= find(temp);
    rank[x] = (rank[x] + rank[temp]) % 3; //关系域更新
    return parent[x]; //根结点
}
void unit(int x,int y)//合并其中也要变权值
{
        parent[y]=x;
        rank[x]=(3+(D-1)+rank[y]-rank[x])%3;
}
void check(int D,int x,int y)
{
    int root1,root2;
    root1=find[x];
    root2=find[y];
    if(root1!=root2) sum++;
    {
        unit(x,y);
    }
    else if(D==1&&rank[x]!=rank[y])
        sum++;
    else if(D==2&&((3 - rank[x] + rank[y]) % 3 != D- 1))//两者rank值只能差1否则矛盾
        sum++;
    }
}
int main()
{
    int n,m,v1,v2,K,;
    scanf("%d%d",&N,&K);
    init(N);
    for(i=0;i<K;i++)
    {
        scanf("%d%d%d",&D,&v1,&v2);
        check(D,v1,v2);
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
