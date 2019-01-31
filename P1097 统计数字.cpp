#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int a[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i+1])
		{
			printf("%d %d\n",a[i],cnt);
			cnt=1;
			continue;
		}
		cnt++;
	}
}
