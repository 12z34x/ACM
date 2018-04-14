#include<stdio.h>
int main()
{
    int n,i,j,k,ans=0,num=0,c=0;
    char ch[100]={};
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
        {
            ch[i]=getchar();
            if(ch[i]=='1') c++;
        }
    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
        {
            num=0;
            for(k=i;k<=j;k++)
            {
                if(ch[k]=='0') num++;
                else if(ch[k]=='1') num--;
                if(num>ans)
                    ans=num;
            }
        }
    printf("%d",c+ans);
}
