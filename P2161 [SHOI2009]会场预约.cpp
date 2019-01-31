#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int tree[N],end[N];
void add(int x,int c)
{
	for(int i=x;i<N;i+=i&-i)
		tree[i]+=c;
}
int ask(int x)
{
	int sum=0;
	for(int i=x;i!=0;i&=i-1)sum+=tree[i];
	return sum;
}
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char c;
		scanf("\n%c",&c);
		if(c=='A')
		{
			int del=0,a,b;
			scanf("%d%d",&a,&b);
			for(int p=ask(b);p!=0;p=ask(b))
			{
				int l=0,r=b;
				for(; l<r;)
				{
					int m=(l+r)>>1;
					if(ask(m)+1<=p)l=m+1;
					else r=m;
				}
				if(end[l]>=a)add(l,-1),del++,ans--;
				else break;
			}
			add(a,1);
			end[a]=b;
			ans++;
			printf("%d\n",del);
		}
		else printf("%d\n",ans);
	}
	return 0;
}
