#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
struct mat
{
    long long d[5][5];
}e,a,b,c,ans,res;
mat operator *(mat x,mat y)
{
    memset(res.d,0,sizeof(res.d));
    for(int i=1;i<=3;i++)
    for(int j=1;j<=3;j++)
    for(int k=1;k<=3;k++)
        res.d[i][j]=res.d[i][j]%mod+x.d[i][k]*y.d[k][j]%mod;
    return res;
}
int main()
{
    int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
	    scanf("%lld",&n);
	    if(n<=3)
	    {
	    	cout<<1<<endl;
	    	continue;
		}
		memset(e.d,0,sizeof(e.d));
		memset(a.d,0,sizeof(a.d));
		memset(b.d,0,sizeof(b.d));
		memset(c.d,0,sizeof(c.d));
		memset(ans.d,0,sizeof(ans.d));
		n-=3;
	    e.d[1][1]=e.d[2][2]=e.d[3][3]=1;	
	    c.d[1][1]=c.d[2][1]=c.d[3][1]=1;
	    a.d[1][1]=a.d[1][3]=a.d[2][1]=a.d[3][2]=1;
		b=e;
	    while(n)
	    {
	        if(n%2==1)
	            b=b*a;
	        n/=2;
	        a=a*a; 
	    }
	    for(int i=1;i<=3;i++)
	    for(int j=1;j<=1;j++)
	    for(int k=1;k<=3;k++)
	        ans.d[i][j]=ans.d[i][j]%mod+b.d[i][k]*c.d[k][j]%mod;
	    cout<<ans.d[1][1]%mod<<endl;	
	}
	return 0;
}
