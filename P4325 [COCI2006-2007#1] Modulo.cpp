#include<bits/stdc++.h>
using namespace std;
int que[45],ans,x;
int main()
{
	for(int i=1;i<=10;i++)
	{
		cin>>x;
		que[x%42]=1;
	}
	for(int i=0;i<45;i++)
		if(que[i])
			ans++;
	cout<<ans<<endl;
}
