#include<bits/stdc++.h>
using namespace std; 
int main()
{
	while(1)
	{
		int ans=0;
		char a[100];
		cin>>a;
		for(int i=0;i<strlen(a);i++)
			ans+=a[i]-'a'+1;
		cout<<ans<<endl;
	}
}
