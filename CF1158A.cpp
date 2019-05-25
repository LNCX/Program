#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100010],b[100010],ans;
int main()
{
	int n,m;
    scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
    {
        scanf("%lld",&a[i]);
        ans+=a[i]*m;
    }
    for(int i=1;i<=m;i++)
        scanf("%lld",&b[i]);
	sort(a+1,a+n+1),sort(b+1,b+m+1);
    if(a[n]>b[1]) return puts("-1"),0;
	for(int i=2;i<=m;i++) ans+=b[i]-a[n];
    if(b[1]!=a[n]) printf("%lld\n",ans+b[1]-a[n-1]);
    else cout<<ans<<endl;
}
