#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int q[N],a[N];
int main()
{
	int m,d;
	cin>>m>>d;
	int t=0,add;
	int l=0,r=0;
	for (int i=1;i<=m;i++)
	{
		char c;
		int x;
		cin>>c>>x;
		if(c=='A')
		{
			add=(t+x)%d;
			while(add>=q[r]&&r!=0)
				r--;
			q[++r]=add;
			a[r]=++l;
		}
		else
		{
			t=q[lower_bound(a+1,a+1+r,l-x+1)-a];
			printf("%d\n",t);
		}
	}
}
