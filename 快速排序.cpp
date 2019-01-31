#include<iostream>
#define maxn 100000
using namespace std;
int a[maxn]={0};
int sort(int l,int r)
{
	int p=l,q=r,med=(l+r)/2;
	while(l<=r)
	{
		while(a[l]<a[med]) l++;
		while(a[r]>a[med]) r--;
		if(l<=r)
		{
			int temp=a[l];
			a[l]=a[r];
			a[r]=temp;
			l++;r--;
		}
	}
	if(p<r) sort(p,r);
	if(q>l) sort(l,q);
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
		sort(0,n-1);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
		cout<<endl;
}
