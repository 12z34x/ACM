#include<stdio.h>
#include<string.h>
int c[1000][1000]={},b[1000][1000]={};//���ݷ�������b����¼�ı任��ʽ�������ҵ�x[i]==y[j]ʱ���ַ����Ӷ��õ������������
void ans(int *x,int *y,int i,int j)
{
    if(i==0||j==0) return;
    if(b[i][j]==1)
    {
        ch[c[i][j]-1]=x[i];
        LCS(x,y,i-1.j-1);
    }
    else if(b[i][j]==2)
        LCS(x,y,i-1,j);
    else LCS(x,y,i,j-1);
}
int LCS(int *x,int *y,int m,int n)//��Ϊx��Ϊy
{
    int i=0,j=0;
    for(i=0;i<=m;i++)
        c[i][j]=0;
    for(j=0;j<=m;j++)
        c[i][j]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(x[i]==y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]=1//�Խ����ƶ�
            }
            else if(c[i-1][j]>c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]=2;
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]=3;
            }
        }
    return c[m][n];
}
int main()
{
    char ch1={},ch2={};
    int i,j,ans,n;
    gets(ch1);
    n=strlen(ch1);
    //gets(ch2);
    for(i=n-1,j=0;i>=0;i--,j++)
    {
        ch2[j]=ch1[i];
    }
    ans(ch1,ch2,n,n);
    printf("%d",n-LCS(ch1,ch2,n,n));//
}
