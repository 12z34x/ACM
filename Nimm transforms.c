#include<stdio.h>
int main()
{
    int n,num=0,j,a[1000]={},i,sum=0,s[1000]={};
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    if(n%2!=0&&a[0]==1)
        for(i=1,j=0;i<n;i+=2,j++)
        {
            s[j]=s[i+1]-s[i]-1;
            sum^=s[j];
        }
    else if(n%2!=0&&a[0]!=1)
    {
        for(i=1,j=1;i<n;i+=2,j++)
        {
            s[j]=s[i+1]-s[i]-1;
            sum^=s[j];
        }
        s[0]=a[0]-2;
        sum^=s[0];
    }
    else
        for(i=0,j=0;i<n;i+=2,j++)
        {
            s[j]=s[i+1]-s[i]-1;
            sum^=s[j];
        }
    for(i=0;i<j;i++)
    {
        if(s[i]>(sum^s[i])) num=1;
    }
    if(num) printf("Georgia will win");
    else printf("Bob will win");
}
