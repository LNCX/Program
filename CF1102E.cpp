#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e5+5,mod=998244353;
struct node
{
    int l,r;
    bool operator<(const node &x) const
    {
        return l<x.l;
    }
};
map<int,node>q;
vector<node>b;
LL power(LL a,LL b)
{
    LL ans=1;
    while(b)
    {
        if(b&1) ans=a*ans%mod;
        b>>=1;a=a*a%mod;
    }
    return ans%mod;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(!q.count(x))
            q[x]=(node){i,i};
        else q[x].r=i;
    }
    for(auto it=q.begin();it!=q.end();it++)
        if(it->second.l!=it->second.r)
            b.push_back(it->second);
    sort(b.begin(),b.end());
    int l=0,r=0;
    for(int i=0;i<b.size();i++)
    {
        if(b[i].l>r)
        {
            n-=r-l;
            l=b[i].l,r=b[i].r;
        }
        else r=max(b[i].r,r);
    }
    n-=r-l;
    cout<<power(2,n-1)<<endl;
    return 0;
}