#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,k,ans,mod=1e9+7,f[N],cnt[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
	cin>>n>>k;
	iota(f,f+n+1,0);
	for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        !w?f[find(u)]=find(v):0;
    }
	for(int i=1;i<=n;i++)
        cnt[find(i)]++;
	for(int i=1;i<=n;i++)
    {
        ll x=1;
		for(int j=1;j<=k;j++)
            x=x*cnt[i]%mod;
		ans=(ans+x)%mod;
	}
    ll x=1;
	for(int i=1;i<=k;i++)
        x=x*n%mod;
	cout<<(x-ans+mod)%mod;
}