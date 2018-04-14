#include<stdio.h>
int main()
{
    int v,i,j,k,N,d[100][100];
    scanf("%d",&N);
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            scanf("%d",d[i][j]);
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            for(k=0;k<N;k++)
                if(d[i][j]>d[i][k]+d[k][j])
                d[i][j]=d[i][k]+d[k][j];
}
