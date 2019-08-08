#include<cstdio>
#include<iostream>
#define N 5005
using namespace std;
int main()
{
	int max=0,l=1,n,s,a,b,f[N]={0},c[N]={0};
	cin>>n>>s>>a>>b;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(a+b>=x)
		{
			c[l]=y;
			l++;	
		}	
	}
	for(int i=1;i<l;i++)
	    for(int v=s;v>=c[i];v--)
			if(f[v]<f[v-c[i]]+1)
				f[v]=f[v-c[i]]+1;
	for(int i=0;i<=s;i++)
		if(f[i]>max)
			max=f[i];
	cout<<max<<endl;
}
