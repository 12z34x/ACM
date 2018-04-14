#include<stdio.h>
#define N 10000
int main()
{
    int a[N]={},b[N]={},n=0,i,j,t,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d %d",&a[i],&b[i]);
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(b[j]<b[j+1])
        {
        t=b[j+1];
        b[j+1]=b[j];
        b[j]=t;
        t=a[j+1];
        a[j+1]=a[j];
        a[j]=t;
        }
    t=0;
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
        if(sum+b[i]>t)
            t=sum+b[i];
            printf("%d ",t);
    }
    printf("%d",t);
    return 0;
}
