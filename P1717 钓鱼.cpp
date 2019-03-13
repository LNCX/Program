#include<bits/stdc++.h>
using namespace std;
const int maxn=30;
struct fish
{
    int f,d;
    bool operator<(const fish &x) const 
    {
        return f<x.f;
    }
}a[maxn];
int n,h,t[maxn],ans;
int solve(int t,int id)
{
    int res=0;
    priority_queue<fish>q;
    for(int i=1;i<=id;i++)
        q.push(a[i]);
    for(int i=1;i<=t&&!q.empty();i++)
    {
        fish x=q.top();
        q.pop();
        res+=x.f,x.f-=x.d;
        if(x.f>0) q.push(x);
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&h);h*=12;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].f);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].d);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&t[i]);
        t[i]+=t[i-1];
    }
    for(int i=1;i<=n;i++)
        ans=max(ans,solve(h-t[i-1],i));
    cout<<ans<<endl;
    return 0;
}