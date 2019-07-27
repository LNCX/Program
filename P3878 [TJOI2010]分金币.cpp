#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=35;
int n,t;
ll a[N],ans;
ll get()
{
    ll res=0;
    for(int i=1;i<=(n>>1);i++)
        res+=a[i];
    for(int i=(n>>1)+1;i<=n;i++)
        res-=a[i];
    return abs(res);
}
void SA()
{
    double T=2000,delta=0.997;
    ll now=ans;
    while(T>1e-10)
    {
		int x=rand()%n+1,y=rand()%n+1;
		swap(a[x],a[y]);
        ll sum=get(),d=sum-now;
        if(d<0) now=sum;
        else
		{
			if(exp(-d/T)*RAND_MAX>rand()) now=sum;
			else swap(a[x],a[y]);
		}
        if(ans>now) ans=now; 
        T*=delta;
    }
}
void solve()
{
    ans=0x3f3f3f3f3f3f3f3f;
    for(int i=1;i<=50;i++)
		SA();
}
int main()
{
    scanf("%d",&t);
    srand(19820817),rand(),rand();
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        solve();
        printf("%lld\n",ans);
    }    
    return 0;
}