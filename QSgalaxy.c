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
int price[1000]={};
int v;
int main()
{
    int i,j,min=INT_MAX,tmp=0,a[1000]={},k=0,num=1,road;
    scanf("%d",&v);
    for(i=1;i<=v;i++)
        scanf("%d",&price[i]);
    for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
        {
            scanf("%d",&road);
            if(i==j) continue;
            e[num].from=i;
            e[num].to=j;
            e[num].rank=road+price[i]+price[j];
            num++;
        }
    flag[1]=0;
    for(j=1;j<v;j++)
    {
        min=INT_MAX;
        for(k=1;k<=v;k++)
        {
            if(flag[k]==0) continue;
            for(i=1;i<=num;i++)
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
}

