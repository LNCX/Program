#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,l,ans=0;
	cin>>x>>y>>l;
	bool h[x+1][y+1]={0};
	for(int i=1;i<=l;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int j=a;j<=c;j++)
		for(int k=b;k<=d;k++)
			h[j][k]=true;
	}
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++)
			if(h[i][j]) ans++;
	cout<<ans<<endl;
	return 0;
}

