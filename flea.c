#include<stdio.h>
void zhiyueshu(int x)
{
    int m,i;
    m=x;
    for(i=2;i*i<=m;i++)
    {
        if(m%i==0)
        {
            p[x][num[x]]=i;
            num[x]++;
        }
        while(m%i==0) m/=i;
    }
    if(m>1)
    {
        p[x][num[x]]=m;
        num[x]++;
    }
}
void computing()
{
    int cnt=num[M];
    for(int i = 1; i < (1<<cnt); i++)//����M����Լ�����������
    {
        int  t = 0 , ret = 1;
        for(int j = 0; j < cnt; j++){
            if(i&(1<<j))//��Բ�ͬ�����Ҫ�õ�M�ĵ�j����Լ��
            {
                t++;
                ret *= P[M][j];//���㹫Լ����M��һ��������Լ��ʱ���൱�ڹ�Լ������Щ��Լ���ĳ˻�
            }
        }
        if(t%2 == 0)
            ans -= pow(M/ret , N);//�����ݳ�ԭ������+��˫��-
        else
            ans += pow(M/ret , N);
    }
    printf("%lld\n" , pow(M , N)-ans);
}

int N,M,p[1000][1000]={},num[1000]={},ans=0;
int main()
{
    int i;
    scanf("%d%d",&N,&M);
    for(i=2;i<=N;i++)
        zhiyueshu(i);
}
