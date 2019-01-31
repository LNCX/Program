#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
const int inf=0x3f3f3f3f;
long long f[maxn],sumt[maxn],sumc[maxn];
int main()
{
	int n,s;
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
	{
		int t,c;
		scanf("%d%d",&t,&c);
		sumt[i]=sumt[i-1]+t;
		sumc[i]=sumc[i-1]+c;
	}
	memset(f,inf,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			f[i]=min(f[i],f[j]+sumt[i]*(sumc[i]-sumc[j])+s*(sumc[n]-sumc[j]));
	cout<<f[n]<<endl;
	return 0;
}
