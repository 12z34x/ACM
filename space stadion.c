#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
struct v
{
    double x;
    double y;
    double z;
    double r;
}*vv;
double ritualrank(double x1,double y1,double z1,double x2,double y2,double z2,double r1,double r2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2))-r1-r2>0?sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2))-r1-r2:0;
}
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
    int i,j,min=INT_MAX,tmp=0,a[1000]={},k=0,num=1;
    scanf("%d",&v);
    for(i=1;i<=v;i++)
    {
        scanf("%ld%ld%ld%ld",&vv[i].x,&vv[i].y,&vv[i].z,&vv[i].r);
    }
    flag[1]=0;
    for(i=1;i<=v;i++)
        for(j=1;j<=v;j++)
        if(j==i) continue;
        else
        {
            e[num].from=i;
            e[num].to=j;
            e[num].rank=ritualrank(vv[i].x,vv[i].y,vv[i].z,vv[j].x,vv[j].y,vv[j].z,vv[i].r,vv[j].r);
            num++;
        }
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
