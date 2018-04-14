#include<stdio.h>
#include<limits.h>
struct edge
{
    int from;
    int to;
    int coust;
}*es;
int E;
int main()
{
    int end,i,a,b,c,d[100]={},n=0;
    scanf("%d%d",end,E);
    for(i=1;i<=E;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        es[i].from=a;
        es[i].to=b;
        es[i].cost=c;
    }
    for(i=2;i<=end;i++)
        d[i]=INT_MAX;
    d[1]=0;
    bool update=ture;
    while(update)
    {
        update=false;
        for(i=1;i<E;i++)
        {
            struct edge e=es[i];
            if(d[e.from]!=INT_MAX&&d[e.to]>d[e.from]+e.cost)
            {
                d[e.to]=d[e.from]+e.cost;
                update=true;
            }
        }
        n++;
    }//最多执行v-1次
    if(n>v-1) printf("存在环，则可以使财富增加",);
    else printf("不可");
}
