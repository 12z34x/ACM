#include <stdio.h>
#include <string.h>
#define MOD  100000000
#define maxn 13

int dp[maxn][1<<maxn];        //每个状态可以放牧方法的总数
int n, m;
int sta[maxn];                //能不能放牧的状态

bool check(int x, int y)      //检查同列有没有相邻的或者x的状态是否可以存在
{
    if (x&y)
        return false;
    return true;
}

bool checkself(int x)         //检查同行有没有相邻的
{
    if (x&(x<<1))
        return false;
    return true;
}

int getresult()
{
    int num = 1<<m;
    for (int i = 0; i < num; i++)
    {
        if (check(i, sta[1]) && checkself(i))//方案与土地状况不冲突，并且方案本身01间隔
            dp[1][i] = 1;//记录第一行方案，每种方案为1
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (!check(j, sta[i]))                    //sta[i]表示i行不能存在的状态,
                continue;
            for (int k = 0; k < num; k++)
            {
                if (check(k, j) && checkself(j) && checkself(k))//本行与上一行不相邻，本行和上一行均10间隔
                    dp[i][j] += (dp[i-1][k]%MOD);//对应与上一行某种方案的各种变化方案均继承其方案数
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < num; i++)
    {
        ans += (dp[n][i]%MOD);//最后一行不同方案数之和
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
                if (!t)
                {
                    sta[i] += (1<<(m-j));            //这里对不能出现的状态做标记
                }
            }
        }
        printf("%d\n", getresult());
    }
    return 0;
}

