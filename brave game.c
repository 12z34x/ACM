#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(n%(m+1)==0)
        printf("second!");
    else printf("first!");
    return 0;
}
