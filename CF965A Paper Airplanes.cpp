#include<bits/stdc++.h>
using namespace std;
int main()
{
	int k,n,s,p;
	scanf("%d%d%d%d",&k,&n,&s,&p);
	cout<<(long long)(ceil((long long)(ceil(n/(double)(s)))*k/(double)(p)));
	return 0;
}
