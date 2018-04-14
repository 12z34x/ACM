#include<stdio.h>
int main()
{
    int i,n,a[1000]={},b[1000]={};
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d",&a[i],&b[i]);
    for(i=0;i<n;i++)
    {
        if(a[i]>11||(a[i]==11&&b[i]>=4))
            printf("No\n");
        else if((a[i]+b[i])%2==0||(a[i]==9&&b[i]==30))
            printf("Yes\n");
        else printf("No\n ");
    }
}
