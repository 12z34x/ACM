#include<stdio.h>
#define N 50
int n,m,z=0,searched=0,b[100][100]={},o,p;
char a[100][100]={};
void dfs(char c,int x,int y)
{
     printf("%d (%d,%d)--%d   ",z,x,y,searched);
    b[x][y]=1;
    if(c=='@')
    {
        if(searched==0)
            {
                searched=1;
                z++;
                o=x;
                p=y;
            }
        if(x>0&&b[x-1][y]==0)
            dfs(a[x-1][y],x-1,y);
        if(x<n-1&&b[x+1][y]==0)
            dfs(a[x+1][y],x+1,y);
        if(y>0&&b[x][y-1]==0)
            dfs(a[x][y-1],x,y-1);
        if(y<m-1&&b[x][y+1]==0)
            dfs(a[x][y+1],x,y+1);
        if(y>0&&x>0&&b[x-1][y-1]==0)
            dfs(a[x-1][y-1],x-1,y-1);
        if(y<m-1&&x>0&&b[x-1][y+1]==0)
            dfs(a[x-1][y+1],x-1,y+1);
        if(y>0&&x<n-1&&b[x+1][y-1]==0)
            dfs(a[x+1][y-1],x+1,y-1);
        if(y<m-1&&x<n-1&&b[x+1][y+1]==0)
            dfs(a[x+1][y+1],x+1,y+1);
        if(x==o&&y==p) searched=0;
    }
    else return;
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    getchar();
    for(i=0;i<n;i++)
         {
             for(j=0;j<m;j++)
             a[i][j]=getchar();
             getchar();
         }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(b[i][j]==0)
            dfs(a[i][j],i,j);
    printf("%d",z);
}
