#include<cstdio>
struct int128
{
    long long hig;
    long long low;
};
int n,m;
long long p=1e18;
int128 ans,f[85][85][85],a[85][85];
int128 max(int128 a,int128 b)
{
	if(a.hig>b.hig)	return a;
	if(a.hig<b.hig) return b;
	if(a.low>b.low) return a;
	if(a.low<b.low) return b;
	return a;
}
int128 operator + (int128 a,int128 b)
{
    int128 k;
    k.low=0,k.hig=0;
    k.low=a.low+b.low;
    k.hig=k.low/p+a.hig+b.hig;
    k.low%=p;
    return k;
}
int128 operator * (int128 a,int b)
{
	int128 k;
	k.low=0,k.hig=0;
	k.low=a.low*b;
	k.hig+=k.low/p+2*a.hig;
	k.low%=p;
	return k;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        scanf("%lld",&a[i][j].low);
	for(int i=1;i<=n;i++)
    for(int len=0;len<m;len++)
    for(int l=1;l+len<=m;l++)
            f[l][l+len][i]=max(f[l+1][l+len][i]+a[i][l],f[l][l+len-1][i]+a[i][l+len])*2;
    for(int i=1;i<=n;i++)
    	ans=ans+f[1][m][i];
    if(ans.hig==0)	printf("%lld",ans.low);
    else	printf("%lld%018lld\n",ans.hig,ans.low);
}
