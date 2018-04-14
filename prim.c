#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>

struct edge
{
    int from;
    int to;
    int rank;
}*e;
int flag[1000]={};
int v,E;
int main()
{
    int i,j,s,min=INT_MAX,tmp=0,a[1000]={},k=0;
    scanf("%d",&s);
    scanf("%d%d",&v,&E);
    for(i=1;i<=E;i++)
        scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].rank);
    while(scanf("%d%d",&i,&j)!=EOF);
        for(i=1;i<=E;i++)
            if(e[i].from==i&&e[i].to==j) e[i].rank=0;//已经建好的路，rank值为0
    flag[1]=0;
    for(j=1;j<v;j++)
    {
        min=INT_MAX;
        for(k=1;k<=v;k++)
        {
            if(flag[k]==0) continue;
            for(i=1;i<=E;i++)
            {
                if(e[i].from==k&&flag[e[i].to]!=1&&e[i].rank<min)
                {
                    min=e[i].rank;
                    tmp=e[i].to;
                    a[j]=i;
                }
            }
        }
         flag[tmp]=1;
    }
     for(j=1;j<=v-1;j++)
        printf("%d-%d %d  ",e[a[j]].from,e[a[j]].to,e[a[j]].rank);
        printf("D=%d",e[a[s]].rank);
}

