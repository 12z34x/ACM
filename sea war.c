#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000]={};
    int i,num=0,a,b,n=0,length=0;
    gets(s);
    n=strlen(s);
    scanf("%d%d",&a,&b);
    for(i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            length++;
            if(length>=b)
                num++;
        }
        else length=0;
    }
    printf("%d",num-a+1>0?num-a+1:0);
}
