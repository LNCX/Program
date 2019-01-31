#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
const double eps=1e-7;
int n,x[maxn],y[maxn];
bool check(double md)
{
    double L=-1e18,R=1e18;
    double dis;
    for(int i=1;i<=n;i++)
	{
        if(2*md<y[i])return false;
        dis=sqrt((2*md-y[i])*y[i]);
        L=max(L,x[i]-dis);R=min(R,x[i]+dis);
    }
    return L<R;
}
int main()
{
	bool flag1=0,flag2=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(y[i]>0) flag1=1; 
		if(y[i]<0) flag2=1;
	}
	if(flag1&&flag2)
	{
		printf("-1\n");
		return 0;
	}
	if(flag2)
		for(int i=1;i<=n;i++)
			y[i]=-y[i];
	//¶þ·ÖÔ²µÄ°ë¾¶
	double l=0,r=1e14;
	for(int i=1;i<=1000;i++)
	{
		double mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	printf("%.6lf\n",l);
	return 0;
}
