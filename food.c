#include<stdio.h>
#include<stdlib.h>
int parent[1000]={};
int rank[1000]={};//Ȩֵ
int sum=0,N,D;
int flag[1000]={};
void init(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        parent[i]=i;//һ�����ְ汾
        rank[i]=1;
    }
}
int find(int x)//��Ȩֵʱ��·��ѹ��
{
    int s;
    s=x;
   while(parent[s]!=s)
    s=parent[s];
    int tmp;
    while(parent[x]!=s)
    {
        tmp=parent[x];
        parent[x]=s;
        x=tmp;
    }
   return s;
}
int findrank(int x) //��Ȩֵʱ��·������
{
    int temp;
    if(x == parent[x])
        return x;
    temp = parent[x]; //·��ѹ��
    parent[x]= find(temp);
    rank[x] = (rank[x] + rank[temp]) % 3; //��ϵ�����
    return parent[x]; //�����
}
void unit(int x,int y)//�ϲ�����ҲҪ��Ȩֵ
{
        parent[y]=x;
        rank[x]=(3+(D-1)+rank[y]-rank[x])%3;
}
void check(int D,int x,int y)
{
    int root1,root2;
    root1=find[x];
    root2=find[y];
    if(root1!=root2) sum++;
    {
        unit(x,y);
    }
    else if(D==1&&rank[x]!=rank[y])
        sum++;
    else if(D==2&&((3 - rank[x] + rank[y]) % 3 != D- 1))//����rankֵֻ�ܲ�1����ì��
        sum++;
    }
}
int main()
{
    int n,m,v1,v2,K,;
    scanf("%d%d",&N,&K);
    init(N);
    for(i=0;i<K;i++)
    {
        scanf("%d%d%d",&D,&v1,&v2);
        check(D,v1,v2);
    }
    for(i=1;i<=n;i++)//��Ϊ�����±��1��ʼ
    {
        if(flag[i]==1)continue;
        num++;
        number[num]=1;
        flag[i]=1;
        for(j=1;j<=n;j++)
            if(find(i)==find(j))
            {
                flag[j]=1;
                number[num]++;
            }

    }
    printf("%d",num);//num-1Ϊ���ٻ���Ҫ����·�ĸ���
    for(i=0;i<num;i++)
        printf("%d",number[i+1]);
}
