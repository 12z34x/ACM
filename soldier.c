#include <stdio.h>
#include <string.h>
#define MOD  100000000
#define number 65

int dp[number][number][number]={};        //r行，r-1行状态j的方案数
int n, m;
int sta[number]={};                //阵地状态的

bool check(int x, int y)      //检查是否满足阵地状态
{
    if (x&y==x)
        return true;
    return false;
}

bool checkself(int x)         //检查同行有没有间隔小于2的
{
    if (x&(x<<2)||x&(x<<1))
        return false;//有间隔小于2的
    return true;
}
int count(int x)
{
    int cout=0;
    while (x!=0)
    {
        if(x%2==1)
            cout++;
    }
    return cout;
}
int getresult()
{
    int num = 1<<m;
    for (int i = 0; i < num; i++)
    {
        if (check(sta[1], i) && checkself(i))//方案与土地状况不冲突，并且方案本身间隔小于2
            dp[1][0][i] = count(i);//记录第一行方案，每种方案为1
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (check(sta[i],j))                    //sta[i]表示i行阵地的状态,
                continue;
            for (int k = 0; k < num; k++)
            {
                 if (k&j) continue;
                 for (int r= 0; r < num; r++)
                {
                    if (r&k||dp[r-1][k][r]==0) continue;                    //sta[i]表示i行阵地的状态,
                    dp[r][k][j]=dp[r][k][j]>dp[r-1][r][k]+count[i]?dp[r][k][j]:dp[r-1][r][k];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
            if(ans>dp[n-1][i][j]) ans=dp[n-1][i][j];
    }
    return ans%MOD;
}

int main()
{
    int t;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &t);
                if (t)
                {
                    sta[i] += (1<<(m-j));            //每行的状态
                }
            }
        }
        printf("%d\n", getresult());
    }
    return 0;
}

