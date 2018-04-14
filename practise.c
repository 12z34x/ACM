int jiecheng(int n)
{
    if(n==1) return 1;
    return n*jiecheng(n-1);
}
