#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
    int i=0,length=0,k=0,j=0,b[N]={},result[N+1]={};
    char a[N][N+1]={};
    gets(a[i]);
    b[i]=strlen(a[i]);
    if(b[i]>length)length=b[i];
    while(strcmp(a[i],"0")!=0)
    {
        i++;
        gets(a[i]);
        b[i]=strlen(a[i]);
        if(b[i]>length)length=b[i];
    }
    for(k=length;k>=0;k--)
    {
        for(j=0;j<i;j++)
        {
            if(b[j]<1)continue;
            result[k]=result[k]+a[j][b[j]-1]-48;
            b[j]--;
        }
        if(result[k]>9)
        {
            result[k-1]=result[k]/10+result[k-1];
            result[k]=result[k]%10;
        }
    }
    i=0;
    while(result[i]==0)i++;
    if(i<=length)
    while(i<=length)
    {
        printf("%d",result[i]);
        i++;
    }
    else printf("0");
    putchar('\n');
   return 0;
}
