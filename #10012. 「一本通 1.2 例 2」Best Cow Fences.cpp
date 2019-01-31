#include<bits/stdc++.h>
using namespace std;
int n,m;
double l,r,e=1e-4,a[100005];
bool check(double x)
{
	double max=-0x7fffffff,min=0;
	double sum[100005]={0};
	for(int i=1;i<=n;i++)
		sum[i]+=a[i]-x+sum[i-1];
	for(int i=m;i<=n;i++)
	{
		if(sum[i]-min>max) max=sum[i]-min;
		if(a[i-m+1]-x+sum[i-m]<min) min=a[i-m+1]-x+sum[i-m];
	}
	if(max>0) 
		return true;
	else return false;	
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		if(a[i]>r) r=a[i];
	}
	while(r-l>e)
	{
		double mid=(r+l)/2.0;
		if(check(mid)) 
			l=mid;
		else r=mid;
	}
	cout<<int(1000*r)<<endl;
}

