#include<stdio.h>
int main()
{
    double dp[1000][1000]={},v;//s��ϵͳ��m������
    int n,s,i,j;
    v=s*n;
    scanf("%d%d",&n,&s);
    dp[n][s]=0;
    for(i=n;i>=0;i--)
        for(j=s;j>=0;j--)
            {
                if(i==n&&j==s) continue;//���������ʼ��Ϊ0��dp[n][s]���Ϊ1Ҫ��ܣ������һ�У�һ������Ԫ�ؼ�ʹ����Ϊ0�Խ����Ӱ��
                dp[i][j]=(1+dp[i+1][j]*(n-i)/n*j/s+dp[i][j+1]*(s-j)/s*i/n+dp[i+1][j+1]*(n-i)/n*(s-j)/s)/(1-i*j/v);//״̬ת��function����
            }
    printf("%d",dp[0][0]);
}
