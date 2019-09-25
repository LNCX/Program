#include<bits/stdc++.h>
using namespace std;
const int MAXA=4e5+1000;
char ss[MAXA];
int s[MAXA],l,r,k,n;
long long f[MAXA];
void solve()
{
    s[++r]=0;l=1;
    for(int i=1;i<=n+k;i++)
    {
	f[i]=f[i-1]+i;
	if(i>k&&ss[i-k]=='1')
    {
	    f[i]=f[s[l]]+i-k;
	}
	if(s[l]<i-2*k) l++;
	while(r>=l&&f[s[r]]>=f[i]) r--;
	s[++r]=i;
    }
    for(int i=n+k-1;i>=1;i--)
	f[i]=min(f[i],f[i+1]);
}
int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",ss+1);
    solve();
    printf("%lld",f[n]);
}