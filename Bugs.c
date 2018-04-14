#include<stdio.h>
int main()
{
    double dp[1000][1000]={},v;//s个系统，m个分类
    int n,s,i,j;
    v=s*n;
    scanf("%d%d",&n,&s);
    dp[n][s]=0;
    for(i=n;i>=0;i--)
        for(j=s;j>=0;j--)
            {
                if(i==n&&j==s) continue;//由于数组初始化为0，dp[n][s]会改为1要规避，而最后一行，一列其他元素即使超项为0对结果无影响
                dp[i][j]=(1+dp[i+1][j]*(n-i)/n*j/s+dp[i][j+1]*(s-j)/s*i/n+dp[i+1][j+1]*(n-i)/n*(s-j)/s)/(1-i*j/v);//状态转移function移项
            }
    printf("%d",dp[0][0]);
}
