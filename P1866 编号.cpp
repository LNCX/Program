#include<bits/stdc++.h>
const int mod=1000000007;
using namespace std;
int a[105];
int main()
{
	int n;
	long long ans=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        ans=ans*(a[i]-(i-1))%mod;
        if(a[i]-i+1<=0)
		{
			ans=0;
			break;
		}
     } 
	cout<<ans<<endl;
    return 0;
}
