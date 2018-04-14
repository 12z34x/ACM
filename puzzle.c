#include<stdio.h>
int kuaisumi(int x,unsigned y)
{
    int a;
    if(!y) return 1;
    a=kuaisumi(x,y/2);
    if(y%2) return a*a*x;
    else return a*a;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    switch(a){
        case 1:
        case 5:
        case 6: printf("%d",a);break;
        case 4:
        case 9: printf("%d",kuaisumi(a,(b-1)%2+1)%10);break;
        default:printf("%d",kuaisumi(a,(b-1)%4+1)%10);
    }
}
