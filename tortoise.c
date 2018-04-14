#include<stdio.h>
float L,N,C,T,VR,VT1,VT2,s[100]={},flag[100]={},charge0,charge1,dp[100][2]={};
int i=0;
float assume(float flag,float charge,float m)
{
    if(flag==1)
    {
        if(C>m)
        {
            charge1=C-m;
            return(T+m/VT1);
        }
        else
        {
            charge1=0;
            return(T+C/VT1+(m-C)/VT2);
        }
    }
    else
    {
        if(charge>m)
        {
            charge0=charge-m;
            return(m/VT1);
        }
        else
        {
            charge0=0;
            return(charge/VT1+(m-charge)/VT2);
        }
    }
}
int main()
{
    float sum=0;
    scanf("%f",&L);
    scanf("%f%f%f",&N,&C,&T);
    scanf("%f%f%f",&VR,&VT1,&VT2);
    charge0=C;
    charge1=C;
    for(i=1;i<=N;i++)
        scanf("%f",&s[i]);
    s[(int)N+1]=L;
    for(i=1;i<=N+1;i++)
    {
        dp[i][0]=assume(0,charge0,s[i]-s[i-1]);
        dp[i][1]=assume(1,charge1,s[i]-s[i-1]);
        if(dp[i][0]>dp[i][1])
        {
            sum+=dp[i][1];
            charge0=charge1;
        }
        else
        {
            sum+=dp[i][0];
            charge1=charge0;
        }
    }
    if(sum<L/VR) printf("What a pity rabbit!");
    else printf("Good job, rabbit!");
}
