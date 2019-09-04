#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll sum[N],ans;
int a[N]={0x3f3f3f3f},n;
class RMQ
{
	private:
		int f[N][21],log[1000005];
	public:
		void init(int *a,int n)
		{
			memset(f,0,sizeof(f));
			log[0]=-1;
			for(int i=1;i<=n;i++)
				log[i]=log[i>>1]+1;
			for(int i=1;i<=n;i++)
				f[i][0]=i;
			for(int j=1;j<=17;j++)
				for(int i=1;i+(1<<j)-1<=n;i++)
				{
					int x=f[i][j-1],y=f[i+(1<<(j-1))][j-1];
					f[i][j]=(a[x]<a[y]?x:y);
				}
		}
		int query(int l,int r)
		{
			int k=log[r-l+1];
			int x=f[l][k],y=f[r-(1<<k)+1][k];
			return a[x]<a[y]?x:y;
		}
}st;
void dfs(int l,int r)
{
	if(r<l) return;
	int k=st.query(l,r);
	ans=max((ll)(sum[r]-sum[l-1])*a[k],ans);
	dfs(l,k-1),dfs(k+1,r);
}
signed main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	st.init(a,n);
	dfs(1,n);
	cout<<ans<<endl;
	return 0;
}