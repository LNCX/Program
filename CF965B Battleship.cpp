#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
char s[maxn][maxn];
pair<int,int>loc;
int a[maxn][maxn],ans[maxn][maxn],maxx;
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	loc.first=1,loc.second=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int flag=1;
			for(int l=j;l<=j+k-1;l++)
				if(s[i][l]=='#'||l>n)
				{
					flag=0;
					break;
				}
			if(flag)
				for(int l=j;l<=j+k-1;l++)
					ans[i][l]++;
			flag=1;
			for(int l=i;l<=i+k-1;l++)
				if(s[l][j]=='#'||l>n)
				{
					flag=0;
					break;
				}
			if(flag)
				for(int l=i;l<=i+k-1;l++)
					ans[l][j]++;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(maxx<ans[i][j])
				{
					maxx=ans[i][j];
					loc.first=i,loc.second=j;
				}
	cout<<loc.first<<" "<<loc.second<<endl;
	return 0;
}
