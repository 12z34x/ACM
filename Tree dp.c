#include <stdio.h>
int main()
{
    long long int n,i,j,number[1000]={},dp[1000][2]={};
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&number[i]);
    dp[0][1]=number[0];
    for(i=1;i<n;i++)
    {
        dp[i][0]=dp[i-1][0]>dp[i-1][1]?dp[i-1][0]:dp[i-1][1];
        dp[i][1]=dp[i-1][0]+number[i];
    }
    printf("%lld",dp[n-1][0]>dp[n-1][1]?dp[n-1][0]:dp[n-1][1]);
}
