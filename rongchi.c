#include<stdio.h>
long long zuheshu(long long x,long long y)
{
    long long m=1,n=1,i,j;
    for(i=0;i<y;i++)
        m*=(y-i);
    for(i=0;i<y;i++)
        n*=(x-i);
    return n/m;
}
//A[1]=a[1]+2*a[2]+3*a[3]+4*a[4],A[2]=a[2]+3*a[3]+6*a[4]��A[3]=a[3]+4*a[4]��A[4]=a[4];a[i]Ϊ����i���߲��ܷţ������߱���ţ�A[i]Ϊi���߲��ɷţ������߿ɷſɲ���
//a[1]+a[2]+a[3]+a[4]=A[1]-A[2]+A[3]-A[4
int main()
{
    long long m,n,k,number=0;
    scanf("%lld%lld%lld",&n,&m,&k);
    number=zuheshu((m-2)*(n-2),k)+2*zuheshu((m-1)*n,k)+2*zuheshu((n-1)*m,k)-4*zuheshu((m-1)*(n-1),k)-zuheshu((m-2)*n,k)-zuheshu(m*(n-2),k)+2*zuheshu((m-1)*(n-2),k)+2*zuheshu((m-2)*(n-1),k);
    printf("%lld",zuheshu(n*m,k)-number);//������-�ֱ����ҽ���1,2,3,4���߲��ŵ����
    return 0;
}
