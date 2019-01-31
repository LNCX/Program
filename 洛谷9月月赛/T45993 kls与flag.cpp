#include<bits/stdc++.h>
using namespace std;
long long ans;
int x,qwq[500005],len=1;
int main()
{
	int n,m;
	cin>>n>>m;
	memset(qwq,0x7fffffff,sizeof(qwq));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		qwq[len]=i-x;
		len++;
		qwq[len]=i+x;
		len++;
	}
	sort(qwq+1,qwq+len);
	int cnt=1;
	for(int i=2;i<=len;i++)
	{
		if(qwq[i]==qwq[i-1]) cnt++;
		else
		{
			ans+=(cnt-1)*cnt/2;
			cnt=1;
		}
	}
	cout<<ans<<endl;
}
