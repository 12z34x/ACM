#include<iostream>
#include<queue>
#define N 10000
using namespace std;
int num;
int goal;
int main()
{
    int a,b,s,step[N]={};
    cin>>s>>goal;
     queue<int> q;
    q.push(s);
    step[s]=1;
    while(!q.empty())
    {

        a=q.front();
        q.pop();
           if(a==goal)
        {
            cout<<step[a]-1<<endl;
            return 0;
        }
        b=a+1;
        if(b<=N&&b>=0&&step[b]==0)
            {
                step[b]=step[a]+1;
                q.push(b);
            }
            if(b==goal)
        {
            cout<<step[b]-1<<endl;
            return 0;
        }
        b=a-1;
        if(b<=N&&b>=0&&step[b]==0)
            {
                step[b]=step[a]+1;
                q.push(b);
            }
              if(b==goal)
        {
            cout<<step[b]-1<<endl;
            return 0;
        }
        b=a*2;
        if(b<=N&&b>=0&&step[b]==0)
            {
                step[b]=step[a]+1;
                q.push(b);
            }
                   if(b==goal)
        {
            cout<<step[b]-1<<endl;
            return 0;
        }
    }  //深度优先
}
