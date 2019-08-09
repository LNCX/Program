#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,ans;
int a[N];
priority_queue<int>q[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int s,r;
        scanf("%d%d",&s,&r);
        q[s].push(r);
    }
    for(int i=1;i<=m;i++)
    {
        int s=0,cnt=0;
        while(!q[i].empty())
        {
            s+=q[i].top();q[i].pop();
            if(s<0) break;
            a[++cnt]+=s;
            ans=max(ans,a[cnt]);
        }
    }
    cout<<ans<<endl;
}