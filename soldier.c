#include <stdio.h>
#include <string.h>
#define MOD  100000000
#define number 65

int dp[number][number][number]={};        //r�У�r-1��״̬j�ķ�����
int n, m;
int sta[number]={};                //���״̬��

bool check(int x, int y)      //����Ƿ��������״̬
{
    if (x&y==x)
        return true;
    return false;
}

bool checkself(int x)         //���ͬ����û�м��С��2��
{
    if (x&(x<<2)||x&(x<<1))
        return false;//�м��С��2��
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
        if (check(sta[1], i) && checkself(i))//����������״������ͻ�����ҷ���������С��2
            dp[1][0][i] = count(i);//��¼��һ�з�����ÿ�ַ���Ϊ1
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (check(sta[i],j))                    //sta[i]��ʾi����ص�״̬,
                continue;
            for (int k = 0; k < num; k++)
            {
                 if (k&j) continue;
                 for (int r= 0; r < num; r++)
                {
                    if (r&k||dp[r-1][k][r]==0) continue;                    //sta[i]��ʾi����ص�״̬,
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
                    sta[i] += (1<<(m-j));            //ÿ�е�״̬
                }
            }
        }
        printf("%d\n", getresult());
    }
    return 0;
}

