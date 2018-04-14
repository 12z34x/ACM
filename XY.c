#include<stdio.h>
#include<string.h>
#define N 500
int main()
{
    int i=0,length[N/2]={},c=0,k=0,l=0,m,d[N]={},j,b[N]={},result[N][N/2]={};
    char a[N][N+1]={};
    gets(a[i]);
    b[i]=strlen(a[i]);
    j=1;
    if(b[i]>length[j])length[j]=b[i];
    while(strcmp(a[i],"\0")!=0)
    {
        i++;
        j=i/2+1;
        gets(a[i]);
        b[i]=strlen(a[i]);
        if(b[i]>length[j])length[j]=b[i];
    }//针对于一对来说，要针对每一对
    for(c=1;c<j;c++)
    {
        d[c]=b[2*c-2]+b[2*c-1];
    for(k=b[2*c-2]+b[2*c-1];k>=0;k--,b[2*c-1]--)
    {

        m=0;
        if(b[2*c-1]>0)
        for(l=b[2*c-2]-1;l>=0;l--,m++)
            result[c][k-m]=result[c][k-m]+(a[2*c-2][l]-48)*(a[2*c-1][b[2*c-1]-1]-48);
        if(result[c][k]>9)
        {
            result[c][k-1]=result[c][k]/10+result[c][k-1];
            result[c][k]=result[c][k]%10;
        }
    }
    }
    for(c=1;c<j;c++)
    {
    i=0;
    while(result[c][i]==0)i++;
    if(i<=d[c])
    while(i<=d[c])
    {
        printf("%d",result[c][i]);
        i++;
    }
    else printf("0");
    putchar('\n');
    }
    putchar('\n');
   return 0;
}
