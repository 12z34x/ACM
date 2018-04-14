#include<stdio.h>
int main()
{
    int n,a[1000],num=0,flag[1000]={},s[1000]={},i,j,number=0,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    s[num]=a[0];
    num++;
    flag[s[num]]=1;
    for(i=1;i<n;i++)
    {
        number=num;
        for(j=0;j<num;j++)
        {
            if(!flag[s[j]-a[i]])
            {
                flag[s[j]-a[i]]=1;
                s[number]=s[j]-a[i];
                number++;
            }
            if(!flag[s[j]+a[i]])
            {
                flag[s[j]+a[i]]=1;
                s[number]=s[j]+a[i];
                number++;
            }
        }
        num=number;
    }
    i=1;
    while(i<=n)
    {
        if(!flag[i])
        {
            ans++;
            printf("%d",i);
        }
    }
    if(!ans) printf("%d",ans);
    return 0;
}
