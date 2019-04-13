#include<bits/stdc++.h>
using namespace std;
int f(int x)
{
	if(x==1)return 1;
	if(x==2)return 2;
	int sum=f(x-1)+f(x-2);
	return sum;
}
int main()
{
	int n;
	while(cin>>n)
	{
		cout<<f(n)<<endl;
	}
}
