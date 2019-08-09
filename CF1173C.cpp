#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,ans,a[N];
deque<int>q;
int main()
{
    cin>>n>>ans;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]=1;
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        q.push_back(x);
    }
    while(a[q.back()+1])
    {
        int x=q.back()+1;
        q.push_back(a[x]);
        a[x]=0;
        a[q.front()]=1;
        q.pop_front();
    }
    
    return 0;
}