#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cout<<(bool)(i%(abs((n-m))/2+1));
    puts("");
    return 0;
}