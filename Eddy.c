#include<stdio.h>
#include<math.h>
int str[2000000000]={};
int main()
{
    long long N,k,i,j,num=0,flag=0;
    scanf("%d",&N);
    for(i=2;i*i<=N)
        for(j=2;(int)pow((double)i,(double)j)<=N;j++)
        {
            flag=0;
            for(k=1;k<=num;k++)
                if(str[k]==(int)pow((double)i,(double)j))
                {
                    flag=1;
                    break;
                }
            if(!flag)
            {
                num++;
                str[num]=(int)pow((double)i,(double)j);
            }
        }
    printf("%d",num+1);
}
