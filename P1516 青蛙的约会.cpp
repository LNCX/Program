#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL x,y,m,n,l;
void exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
	if(!b)
	{
		x=1;
		y=0;
		d=a;
	}
	else
	{
		exgcd(b,a%b,d,x,y);
		int t=x;x=y;y=t-a/b*y;
	}
}
int main()
{
	LL a,b,d;
	scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l);
	if(n<m)
	{
		swap(m,n);
		swap(x,y);
	}
	exgcd(n-m,l,d,a,b);
	if((x-y)%d!=0||m==n)
		cout<<"Impossible"<<endl;
	else printf("%lld",(a*(x-y)/d%(l/d)+(l/d))%(l/d));
	return 0;
}
