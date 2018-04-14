#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>
#include<iostream>
using namespace std;
int status[2048]={},num=0,ans=0,dp[100][2048]={};
void check(int z)//求出所有每行合法状态，不能有相邻1
{
    for(int i=0;i<pow(2,z);i++)
    {
        if((i<<0x1)&i)
        {
            continue;
        }
        else
        {
            status[num]=i;
            num++;
        }
    }
}
void initial(int y)
{
    check(y);
    for(int i=0;i<num;i++)
    {
        dp[0][i]=1;
    }
}
void calculate(int x,int y)
{
    initial(y);
    for(int i=1;i<x;i++)
    {
        for(int j=0;j<num;j++)
        {
            for(int k=0;k<num;k++)
            {
                if(status[k]&status[j])
                    continue;
                    //cout<<status[k]<<endl;
                else {dp[i][j]+=dp[i-1][k];}

            }
        }
    }
}
int main()
{
    int a,m[100]={},n[100]={};
    scanf("%d",&a);
    for(int i=0;i<a;i++)
        scanf("%d%d",&m[i],&n[i]);
    for(int i=0;i<a;i++)
    {
        if(m[i]>n[i]) {swap(m[i],n[i]);}
        calculate(m[i],n[i]);
        for(int j=0;j<num;j++)
            ans+=dp[m[i]-1][j];
        cout<<ans<<endl;
        ans=0;
        num=0;
    }
    return 0;
}
