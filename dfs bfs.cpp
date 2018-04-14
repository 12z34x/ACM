#include<stdio.h>
#include<queue>//1548
#define N 5
int ans=10000000;
int num;
int goal;
int number[N]={};
int florr[N]={};
void dfs(int n,int step)
{
    if(n>num||n<1) return;
    if(n==goal)
    {
        if(ans>number[n]) ans=number[n];
        return;
    }
    if(number[n]<=step) return;//已经到过了第n层
    number[n]=step;
    dfs(n+florr[n],step+1);
    dfs(n-florr[n],step+1);

}
int main()
{
    int a,b,s,step[N]={};
    scanf("%d",&num);
    if(num==0) return 0;
    scanf("%d %d",&s,&goal);
    for(i=1;i<=num;i++)
    {
        scanf("%d",&florr[i]);
    }
     queue<int> q;
    q.push(s);
    step[s]=-1;
    while(!q.empty())
    {
          if(b==goal)
        {
            printf("%d"step[b]);
            return 0;
        }
        a=q.pop();
        b=a+florr[a];
        if(b<=num&&b>=1&&step[b]==0)
            {
                step[b]=step[a]+1;
                q.push(b);
            }
        b=a-florr[a];
        if(b<=num&&b>=1&&step[b]==0)
            {
                step[b]=step[a]+1;
                q.push(b);
            }
    }  //深度优先
    dfs(s,0);
}
