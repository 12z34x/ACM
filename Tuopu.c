#include<stdio.h>
int indegree[100]={};
int main()
{
    int N,M,i,j,min,a,b,G[500][500]={},ans[500]={},num=0,flag[500]={};
    scanf("%d%d",&N,&M);
    min=N-1;
    for(i=0;i<M;i++)
    {
        scanf("%d%d",&a,&b);
        G[a][b]=1;
        indegree[b]++;
    }
    while(num<N)
    for(i=0;i<N;i++)
    {
        if(flag[i]) continue;
        if(indegree[i]==0&&i<min)
        {
            min=i;
            ans[num]=min;
            num++;
            flag[min]=1;
        }
        for(j=0;j<N;j++)
            if(G[min][j])
            {
                indegree[j]--;
                G[min][j]=0;
            }
    }
    for(i=0;i<N;i++)
        printf("%d",ans[i]);
}
