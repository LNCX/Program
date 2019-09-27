#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,inf=0x3f3f3f3f;
char s[N];
int T,n,t[N];
int main()
{ 
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++)
			t[i]=s[i]-'0';
		bool flag=true;
		for(int k=0;k<=9;k++)
		{
			bitset<N>vis;
			vector<int>a,b;
			a.push_back(inf),b.push_back(inf);
			for(int i=n;i>=1;i--)
			{
				if(t[i]<=a.back()&&t[i]<=k) a.push_back(t[i]),vis[i]=0;
				else b.push_back(t[i]),vis[i]=1;
			}
			flag=true;
			for(int i=1;i<b.size();i++)
				if(b[i]>b[i-1])
				{
					flag=false;
					break;
				}
			if(b.back()<k) flag=false;
			if(flag)
			{
				for(int i=1;i<=n;i++)
					printf("%d",vis[i]+1);
				puts("");
				break;
			}
		}
		if(!flag)puts("-");
	}
	return 0;
}