#include<stdio.h>
int main()
{
    int n,a[10000]={},i,sum=0,max=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        if(a[i]>max) max=a[i];
    }
    for(sum-max>max-1) printf("Yes");
    else printf("No");
}
