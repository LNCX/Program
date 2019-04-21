#include<queue>
#include<map>
#include<cstdio>
#include<iostream>
using namespace std;
priority_queue<int>q;
map<int,int>mp;
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        if(!mp.count(t))
        {
            mp[t]++;
            if(mp.size()>3)
            {
                puts("-1");
                return 0;
            }
            else q.push(t);
        }
    }
    switch(q.size())
    {
        case 1:
        {
            puts("0");
            break;
        }
        case 2:
        {
            int a=q.top();q.pop();
            int b=q.top();
            if((a-b)%2==0)cout<<(a-b)/2<<endl;
            else cout<<a-b<<endl;
            break;
        }
        case 3:
        {
            int a=q.top();q.pop();
            int c=q.top();q.pop();
            int b=q.top();
            if((a-b)%2==0&&a-(a-b)/2==c)cout<<(a-b)/2<<endl;
            else puts("-1");
            break;
        }
    }
    return 0;
}