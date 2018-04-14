#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000]={},T[1000]={};
    int i,next[1000]={},j,k,num=0,location[1000]={};
    gets(s);
    gets(T);
    j=-1;
    next[0]=-1;
    for(i=0;i<strlen(T)-1;)//初始化数组
    {
        if(j==-1||T[i]==T[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else j=next[j];
    }
    j=0;
    i=0;
    while(i<strlen(s))
    {
        if(T[j]==s[i])
        {
            j++;
            i++;
            if(j==strlen(T))
            {
                location[num]=i-j;
                num++;
                }
        }
        else j=next[i];
    }
    for(i=0;i<num;i++)
        printf("%d\n",location[i]);
}
