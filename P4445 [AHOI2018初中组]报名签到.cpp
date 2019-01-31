#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[100001];
	long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
		cin>>a[i];
    for(int i=2;i<=n;i++)
        ans+=max(a[i],a[i-1]);
    cout<<ans<<endl;
}
