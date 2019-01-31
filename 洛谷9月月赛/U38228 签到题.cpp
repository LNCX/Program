#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long sum=1,k,m,n=1;
	cin>>k>>m;
	while(sum%m!=k)
	{
		sum*=10;
		sum+=1;
		n++;
	}
	cout<<n<<endl;
}

