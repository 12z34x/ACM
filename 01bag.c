#include<stdio.h>
int main()
{
    int i,v,N,V,f[1000]={},c[1000],w[1000];
    scanf("%d%d",&N,&V);
    for(i=1;i<=N;i++)
    {
        scanf("%d%d",&c[i],&w[i]);
    }
    for(i=1;i<=N;i++)
        for(v=V;v>=0;v--)//���򣬷�ֹ�ո��µ�ֵ��ͬһiѭ��������ֵ������
            if(v-c[i]<0) continue;
            else
            f[v]=f[v]>f[v-c[i]]+w[i]?f[v]:f[v-c[i]]+w[i];//��Ŀǰ�����û���ѡ�����Ʒ������ѡ�����Ʒ�����ķ�����ѡ����Ʒ��
    printf("%d",f[v]);
}
