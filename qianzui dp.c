#include<stdio.h>
int main()
{
    int i,j,k,n,c,x[10000]={},t,y[10000]={},s[10000]={},num[10]={},dp[10][100][100]={},x1,y1,x2,y2,ans=0;
    scanf("%d%d%d",&n,&c,&t);
    for(i=0;i<n;i++)
        {
            scanf("%d%d%d",&x[i],&y[i],&s[i]);
            dp[s[i]][x[i]][y[i]]++;
        }
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    for(i=0;i<=c;i++)
        for(j=x1;j<=x2;j++)
            for(k=y1;k<=y2;k++)
                num[i]+=dp[i][j][k];
    for(i=0;i<=c;i++)
    {
        ans+=num[i]*((i+t)%(c+1));
    }
    printf("%d",ans);
}
