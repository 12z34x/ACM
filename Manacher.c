#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000]={},c[1000]={};
    int i,j,maxright=0,pos=0,RL[1000]={},ans=0,start=0;
    gets(s);
    for(i=0,j=0;i<=strlen(s);i++)//Ô¤´¦Àí×Ö·û´®
    {
        if(i%2==0) c[i]='#';
        else
        {
            c[i]=s[j];
            j++;
        }
    }
    for(i=0;i<strlen(c);i++)
    {
        if(i>=maxright)
        {
            while(i-j>=0&&s[i-j]==s[i+j])
            {
                RL[i]++;
                j++;
            }
            j=0;
            pos=i;
            maxright=RL[i]-1+i;
            if(RL[i]-1>ans)
            {
                ans=RL[i]-1;
                start=i;
            }
        }
        else
        {
            if(RL[2*pos-i]>RL[pos])
            {
                pos=i;
                maxright=RL[2*pos-i]-1+i;
            }
            else continue;
    }
    printf("%d%d",&ans,&start);
}
