#include<stdio.h>
int main()
{
    int i,sum=0,n,a[1000]={},num=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum^=a[i];
    }
    for(i=0;i<n;i++)
        if(a[i]>(sum^a[i]))
            num++;
    printf("%d",num );
}
