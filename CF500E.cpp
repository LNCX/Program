#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e5+5;
struct node
{
    int l,r,id;
}a[maxn];
deque<int> q;
vector<int> b[maxn];
LL sum[maxn],ans[maxn];
int n,m,l[maxn],r[maxn],x[maxn],y[maxn],fa[maxn],pos[maxn];
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void solve(int x,int id)
{
    int tmp=y[id];
    ans[id]=sum[x]-sum[find(tmp)];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].r+=a[i].l;
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        b[x[i]].push_back(i);
    }
    for(int i=n;i>0;i--)
    {
        l[i]=a[i].l,r[i]=a[i].r;    
        while(!q.empty()&&l[q.front()]<=r[i])
        {
            r[i]=max(r[i],r[q.front()]);
            fa[find(q.front())]=i;
            q.pop_front();
        }
        if(!q.empty())sum[i]=sum[q.front()]+l[q.front()]-r[i];
        else sum[i]=0;
        q.push_front(i);
        for(int j=0;j<b[i].size();j++)
            solve(i,b[i][j]);
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
    return 0;
}