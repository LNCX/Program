#include<bits/stdc++.h>
using namespace std;
int deal(int x)
{
	int i,sum=1;
	for(i=2;i<sqrt(x);i++)
		if(x%i==0) sum+=(i+x/i);
	if(i*i==x) sum+=i;
	return sum;
}
int main()
{
    int s;
	cin>>s;
	for(int i=s+1;;i++)
	{
		int j=deal(i);
		if(deal(j)==i&&i!=j)
		{
			cout<<i<<" "<<deal(i)<<endl;
			return 0;
		}
	}
}

