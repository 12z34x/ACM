#include <stdio.h>
#include <string.h>
#define MOD  100000000
#define maxn 13

int dp[maxn][1<<maxn];        //ÿ��״̬���Է�������������
int n, m;
int sta[maxn];                //�ܲ��ܷ�����״̬

bool check(int x, int y)      //���ͬ����û�����ڵĻ���x��״̬�Ƿ���Դ���
{
    if (x&y)
        return false;
    return true;
}

bool checkself(int x)         //���ͬ����û�����ڵ�
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
        if (check(i, sta[1]) && checkself(i))//����������״������ͻ�����ҷ�������01���
            dp[1][i] = 1;//��¼��һ�з�����ÿ�ַ���Ϊ1
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (!check(j, sta[i]))                    //sta[i]��ʾi�в��ܴ��ڵ�״̬,
                continue;
            for (int k = 0; k < num; k++)
            {
                if (check(k, j) && checkself(j) && checkself(k))//��������һ�в����ڣ����к���һ�о�10���
                    dp[i][j] += (dp[i-1][k]%MOD);//��Ӧ����һ��ĳ�ַ����ĸ��ֱ仯�������̳��䷽����
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < num; i++)
    {
        ans += (dp[n][i]%MOD);//���һ�в�ͬ������֮��
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
                    sta[i] += (1<<(m-j));            //����Բ��ܳ��ֵ�״̬�����
                }
            }
        }
        printf("%d\n", getresult());
    }
    return 0;
}

