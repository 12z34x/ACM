#include<stdio.h>
int main()
{
    long long n,i,j,a[10000]={},b[10000]={},ans[10000]={},num;
    char s[10000]={};
    gets(s);
    scanf("%lld",&num);
    for(i=0;i<num;i++)
        scanf("%lld%lld",&a[i],&b[i]);
    for(j=0;j<num;j++)
        for(i=a[j]-1;i<=b[j]-2;i++)
            if(s[i]==s[i+1]) ans[j]++;
    for(j=0;j<num;j++)
        printf("%lld\n",ans[j]);
}
