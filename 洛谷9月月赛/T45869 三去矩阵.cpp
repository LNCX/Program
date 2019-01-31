#include<bits/stdc++.h>
using namespace std;
char a[2005][2005];
int main()
{
	int n,q,x,y;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		int temp=x;
		x=n-y+1,y=temp;
		int ans=1,mid=1;
		int l=x-1,r=x+1;
		while(1<=l&&r<=n)
		{
			if(a[x][l]==a[x][r])
			{
				mid+=2;
				l--;r++;
			}
			else break;
		}
		ans=max(mid,ans);
		mid=1;
		int u=y-1,d=y+1;
		while(1<=u&&d<=n)
		{
			if(a[u][y]==a[d][y])
			{
				mid+=2;
				u--;d++;	
			}
			else break;
		}
		ans=max(mid,ans);
		cout<<ans<<endl;
	}
}

