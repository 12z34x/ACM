#include<stdio.h>
#define MAX 10000
int a[200][200]={};
int start;
/*int ciduan(int v)
{
    //����v�Ĵζ�·����D[u]+a[u][v]����̵ģ����и�·����ΪD[v]
    int w,min=INT_MAX;
    for(w=1;w<N;w++)
    {
        if(w==v||update[v]==w)continue;//�ζ�·������Ϊd[u]+a[u][v]������ߣ�����d[v]·����ͬ��
        if(D[w]+a[w][v]<min)
            min=D[w]+a[w][v];
    }
    return min;
}*/
int main()
{
    int N,v,w,i,j,end,tmp,min,D[200]={},flag[200]={};//update[N]={};
    scanf("%d",&N);
    flag[0]=1;
     for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            a[i][j]=INT_MAX;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
        {
            scanf("%d",&a[i][j]);
            a[i][j]=a[j][i]=a[i][j]>a[j][i]?a[j][i]:a[i][j];//�����رߣ�a[i][j]������a[j][i]����ȣ�ȡ�����н�Сֵ
            D[j]=a[0][j];
            //second[j]=INT_MAX;
        }
    scanf("%d%d",&start,&end);

    flag[start]=1;
     for(i=0;i<N;i++)
       {

        for(j=0;j<N;j++)
        {
            D[j]=a[start][j];
        }
        //update[i]=start;
       }
    for(i=0;i<N-1;i++)
    {
        min=10000;
        for(w=0;w<N;w++)
        {
            if(flag[w]) continue;
                if(D[w]<min)
                {
                    min=D[w];
                    v=w;
                }
        }
        flag[v]=1;
        for(w=0;w<N;w++)
        {
            if(flag[w]==1)continue;
            if(a[v][w]+D[v]<D[w])
                {D[w]=a[v][w]+D[v];
                update[w]=v;}
        }
    }
    //scanf("%d",&sec);
    //printf("%d",ciduan(sec));
    printf("%d",D[end]);
}
