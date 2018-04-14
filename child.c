#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 100
int main()
{
    long long int i=0,j=0,k=0,n=0,number=0,digit=0,multipulate=0;
    char a[N]={},b[N]={},c[N]={},d,m[N];
    gets(c);
    while(c[i]!=' ')
    {
        a[i]=c[i];
        i++;
    }
    k=i-1;
    while(c[i]==' ') i++;
    d=c[i];
    i++;
    while(c[i]==' ') i++;
    while(c[i]!='\0')
    {
        b[j]=c[i];
        j++;
        i++;
    }
    j--;
    for(i=0;i<=j;i++)
    {
        number=10*number+b[i]-48;
    }

    if(d=='/')
    {
        for(n=0;n<=k-j;n++)
        {
            for(i=0;i<=j+n;i++)
            {
                multipulate=10*multipulate+a[i]-48;
            }
            m[n]=multipulate/number+48;
            if(m[n]==48)
            {
                multipulate=0;
                continue;
            }
            digit=multipulate%number;
            for(i=n+j;i>=n;i--)
            {
                if(digit!=0)
                {
                    a[i]=digit%10+48;
                    digit=digit/10;
                }
                else a[i]=48;
            }
            multipulate=0;
        }
        i=0;
        while(m[i]==48) i++;
        for(;m[i]!='\0';i++)
            printf("%d",m[i]-48);
        return 0;
    }
    else
    {
          for(n=0;n<=k-j;n++)
        {
             for(i=0;i<=j+n;i++)
            {
                multipulate=10*multipulate+a[i]-48;
            }
            m[n]=multipulate/number+48;
            if(m[n]==48)
            {
                multipulate=0;
                continue;
            }
            digit=multipulate%number;
            if(n!=k-j)
            for(i=n+j;i>=n;i--)
            {
                if(digit!=0)
                {
                    a[i]=digit%10+48;
                    digit=digit/10;
                }
                else a[i]=48;
            }
            multipulate=0;
        }
        printf("%d",digit);
        return 0;
    }

}
