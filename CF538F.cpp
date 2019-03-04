#include<bits/stdc++.h>
const int N=2e5+5; 
using namespace std;
int a[N],n,sum[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
    {
		int v=i-2,t;
		for(int j=1;j<=i-2;j=t+1)
        {
			t=v/(v/j);
			if(a[(i-2)/j+1]>a[i]) sum[j]++,sum[t+1]--;
		}
		if(a[1]>a[i]) sum[i-1]++,sum[n]--;
	}
	for(int i=1;i<n;i++)
    {
		sum[i]+=sum[i-1];
		printf("%d ",sum[i]);
	}
	return 0;
}
