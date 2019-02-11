#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int l[maxn],r[maxn],w[maxn],size[maxn],ans=-0x7fffffff;
void dfs(int u)
{
    size[u]=1;
    if(l[u]!=-1)
    {
        dfs(l[u]);
        size[u]+=size[l[u]];
    }
    if(r[u]!=-1)
    {
        dfs(r[u]);
        size[u]+=size[r[u]];
    }
}
bool check(int x,int y)
{
    if((x==-1&&y==-1)||(x!=-1&&y!=-1&&w[x]==w[y]&&check(l[x],r[y])&&check(l[y],r[x])))
        return true;
    return false;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    	scanf("%d",&w[i]);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&l[i],&r[i]);
    dfs(1);
    for(int i=1;i<=n;i++)
        if(check(l[i],r[i]))
            ans=max(ans,size[i]);
    cout<<ans<<endl;
    return 0;
}