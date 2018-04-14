#include<stdio.h>//最好及时开辟数组，用指针判空来判断是否数组结束遍历
#include<stdlib.h>
#include<string.h>
#define N 10000
#define LEN sizeof(struct CTree)
long long n,b[100]={},ii=0,jj=0,kk=0;
char ch[1000][1000]={};
int order;
struct CTree
{
    char *s;
    int number;
    struct CTree *child[];
};
void init(struct CTree *T)
{
    int i,j=0,k=0;
    if(T==NULL ||i>n-1)
    {
        order--;
        return;
    }
    i=T->number+1;
    order++;
    while(i<=n-1)
    {
        T->child[j]= (struct CTree *)malloc(LEN);
        strcpy(T->child[j]->s,T->s);
        T->child[j]->s[order]=i+48;
        i++;
        j++;
    }

    for(k=0;k<=j;k++)
        init(T->child[k]);
}
void bianli(struct CTree *T)
{
    int i=0;
    if(T->child[i]==NULL)
    {
        ch[ii]=T->s;
        ii++;
        return;
    }
    while(T->child[i]!=NULL)
        bianli(T->child[i]);
}
int cmp(int a[],int d[])
{
    int i=0,right=0;
    for(i=0;i<30;i++)
    {printf(" -%d-%d- ",a[i],d[i]);
        if(a[i]!=d[i])
        {
            right=1;
            break;
        }
        i++;

    }
    return(right);
}
int main()
{
    long long k,i=0,j,p,num=0,ans=0,m=0,a[100]={},c[N][19]={},flag=0;
    struct CTree *head;
    head=(struct CTree *)malloc(LEN);
    head->s[0]=order+48;
    head->number=b[i];
    init(head);
    scanf("%lld%lld",&n,&k);
    for(j=1;j<=n-1;j++)
    {
        p=j;
        while(p!=0)
        {
            a[i]=p%k;
            p=p/k;
            i++;
        }
        m=i-1;
        for(i=0;i<=m;i++)
            b[j]+=a[i];
        b[j]%=k;
        i=0;
    }
    binali(head);
    while(jj=0;jj<ii;jj++)
    {
        kk=0;
        while(ch[jj][kk]!='\0')
            {
                c[num][kk]=b[ch[jj][kk]];
                kk++;
            }
        for(k=0,flag=0;k<num;k++)
                if(!cmp(c[k],c[num]))
                    {
                        flag=1;
                        break;
                    }
            if(!flag) ans++;
            num++;
    }
    for(i=0;i<=n-1;i++)
    {
        ii=0;
        bianli(head->child[i]);
        while(jj=0;jj<ii;jj++)
        {
            kk=0;
            while(ch[jj][kk]!='\0')
            {
                c[num][kk]=b[ch[jj][kk]];
                kk++;
            }
            for(k=0,flag=0;k<num;k++)
                if(!cmp(c[k],c[num]))
                    {
                        flag=1;
                        break;
                    }
            if(!flag) ans++;
            num++;
        }
    }
    printf(" %lld",ans);//求不同的连续子序列个数
}

