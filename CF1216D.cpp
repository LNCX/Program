#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000000];
int x,y,Max;
long long ans;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int solve()
{
    for(int i=1;i<=n;i++) 
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    Max=a[n];
    while(a[n]==Max&&n) n--;
    if(!n) return printf("%d %d\n",0,0),0;
    y=Max-a[1];
    for(int i=1;i<=n;i++)
    {
	    x=Max-a[i];
	    y=gcd(y,x);
    }
    for(int i=1;i<=n;i++)
    {
	    x=Max-a[i];
	    ans=ans+x/y;
    }
}
int main()
{
    scanf("%d",&n);
    solve();
    printf("%lld %d",ans,y);
}