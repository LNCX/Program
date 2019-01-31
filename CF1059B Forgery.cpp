#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],b[1005][1005]; 
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		char s[1005];
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
			if(s[j]=='#') a[i][j]=1;
	}
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m-1;j++)
		{
			bool flag=1;
			for(int l=i-1;l<=i+1;l++)
				for(int m=j-1;m<=j+1;m++)
				if(a[l][m]==0&&(l!=i||m!=j))
				{
					flag=0;
					break;
				}
			if(flag)
			{
				for(int l=i-1;l<=i+1;l++)
					for(int m=j-1;m<=j+1;m++)
						if(l!=i||m!=j)
							b[l][m]=1;			
			}				
		}	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=b[i][j])
			{
				printf("NO\n");
				return 0;
			}
		}
		printf("YES\n");
	return 0;
}
