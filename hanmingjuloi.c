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
    char ch[1000][7]={};
    int i=0,j,min=INT_MAX,tmp=0,a[1000]={},k=0,num=0;
    while(scanf("%s",&ch[num])!=EOF);
        num++;
        v=num+1;
        num=1;
     for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
        if(j==i) continue;
        else
        {
            e[num].rank=0;
            e[num].from=i;
            e[num].to=j;
            for(k=0;k<7;k++)
                if(ch[i][k]!=ch[j][k])
                    e[num].rank++;
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

