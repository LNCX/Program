#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int k,n;
LL ar[100005],A,B;
int find(int x) 
{
	int l=0,r=k-1;
	int ans=-1;
	while(l<=r) 
    {
		int mid=(l+r)/2;
		if(ar[mid]<=x) 
        {
			ans=mid;
			l=mid+1;
		}
        else r=mid-1;
	}
	return ans;
}
LL f(int pos,int l, int r) 
{
	LL x=find(r)-find(l-1);
	if(x==0) return A;
	else if (pos==0) return x*(1<<pos)*B;
	else 
    {
		int mid=l+(1<<(pos-1));
		return min(x*(1<<pos)*B,f(pos-1,l,mid-1)+f(pos-1,mid,r));
	}
}
int main() 
{
	scanf("%d%d%lld%lld",&n,&k,&A,&B);
	for(int i=0;i<k;i++) 
		scanf("%lld",&ar[i]);
	sort(ar,ar+k);
	printf("%lld\n",f(n,1,(1<<n)));
	return 0;
}