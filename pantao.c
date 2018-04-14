#include<stdio.h>
#define N 30
int n[N]={};
int j=0;
int pantao(int m)
{
    if(m==n[j]) return 1;
    else return pantao(m+1)*2+1;

}
int main()
{
    int i=0;
    scanf("%d",&n[i]);
    while(n[i]!=-1)
    {
        i++;
        scanf("%d",&n[i]);
    }
    while(j<i)
    {
        printf("%d\n",pantao(1));
        j++;
    }
}
