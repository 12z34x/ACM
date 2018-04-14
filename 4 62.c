#include<stdio.h>
int n,m,num1=0,num2=0,a[10000]={},b[10000]={},dp[1000][1000]={};
void number(int y)
{
    int i,j,k;
    for(i=1;i<=y;i++)
    {
        for(j=0;j<=9;j++)
        {
            if(j==4) dp[i][j]=0;
            else if(i==1)
            dp[i][j]=1;
            else if(i>1&&j==6)
                for(k=0;k<=9;k++)
                    if(k==2) continue;
                    else dp[i][j]+=dp[i-1][k];
            else
                for(k=0;k<=9;k++)
                    dp[i][j]+=dp[i-1][k];
        }
    }

}
int main()
{
    int i=1,j=1,c,d,e=0;
    scanf("%d%d",&n,&m);
    while(n!=0)
    {
        a[i]=n%10;
        i++;
        n=n/10;
    }
    i--;
    while(m!=0)
    {
        b[j]=m%10;
        j++;
        m=m/10;
    }
    j--;
    number(j);
        for(c=i;c>=1;c--)
    {
        if(a[c]!=0)
            for(e=0;e<=a[c]-1;e++)
                num1+=dp[c][e];
    }
    for(d=j;d>=1;d--)
    {
        if(b[d]!=0)
            for(e=0;e<=b[d]-1;e++)
                num2+=dp[d][e];
    }
    printf("%d",num2-num1+1);
}
