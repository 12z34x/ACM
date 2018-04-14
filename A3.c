#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 100
int main()
{
    int i=0,j=0,k=0,b[N][3]={},A[N][3]={},B[N][3]={},l=0,length[N]={},n=0;
    char a[N][N][N]={};
    while(scanf("%d %d %d",&A[i][0],&A[i][1],&A[i][2])!=EOF)
        i++;
    for(j=0;j<i;j++)
        {
            for(k=0;k<3;k++)
            {
                l=0;
                while(A[j][k]!=0)
                {
                    a[j][k][l]=A[j][k]%10+48;
                    A[j][k]=A[j][k]/10;
                    l++;
                }
            }

        }
    for(j=0;j<i;j++)
    {
            for(k=3;k<=99;k++)
        {
        for(l=0;a[j][k-1][l]!='\0'||a[j][k-2][l]!='\0'||a[j][k-3][l]!='\0';l++)
        {
            for(n=k-3;n<=k-1;n++)
             if(a[j][n][l]=='\0') continue;
            else
            a[j][k][l]=a[j][k][l]+a[j][n][l]-48;
              if(a[j][k][l]>9)
            {
            a[j][k][l+1]=a[j][k][l]/10+a[j][k][l+1];
            a[j][k][l]=a[j][k][l]%10;
            }
        a[j][k][l]+=48;
        }
        a[j][k][l]+=48;
        }
    }
        for(j=0;j<i;j++)
        {
            k=strlen(a[j][99]);
            while(a[j][99][k]<=48) k--;
            for(;k>=0;k--)
            {
                printf("%d",a[j][99][k]-48);
            }
        }

}
