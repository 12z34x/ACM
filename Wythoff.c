#include<stdio.h>
int main()
{
    int a,b,i=1,shang,right;
    float k=1.618;
    scanf("%d%d",&a,&b);
    shang=b-a;
    right=(int)shang*k;
    if(right==a)
    {
        printf("0\n");
        return 0;
    }
    else
        printf("1\n");
        if(right<a)
    {
        printf("%d%d",right,right+shang);
    }
    while(a+i<b)
    {
        if((int)i*k==a)
        {
            printf("%d%d",a,a+i);
            break;
        }
        i++;
    }
    i=1;
    right=(int)k*i;
    while(right<a-i)
    {
        if((a-i)==right)
        {
            printf("%d%d",a-i,a);
            break;
        }
        i++;
    }
    i=shang+1;
    while((int)(i*k)<a)
    {
        if((int)i*k==a-i)
        {
            printf("%d%d",a-i,b);
            break;
        }
        i++;
    }
}