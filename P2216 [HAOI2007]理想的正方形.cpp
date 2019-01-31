#include<bits/stdc++.h>
const int maxn=1005;
int min=0x3f3f3f3f,max=-1,ans=0x3f3f3f3f;
int a[maxn][maxn];
int f1[maxn][maxn],f2[maxn][maxn];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
	{
		int l=1,r=0;
		int q1[maxn]={0},q2[maxn]={0};
		int num1[maxn]={0},num2[maxn]={0};
		for(int j=1;j<=m;j++)
		{
			while(num1[l]<j-k+1&&l<=r) l++;
			while(a[i][j]>=q1[r]&&l<=r) r--;
			num1[++r]=j;q1[r]=a[i][j];
			f1[i][j]=q1[l];
		}
		l=1,r=0;
		for(int j=1;j<=m;j++)
		{
			while(num2[l]<j-k+1&&l<=r) l++;
			while(a[i][j]<=q2[r]&&l<=r) r--;
			num2[++r]=j;q2[r]=a[i][j];
			f2[i][j]=q2[l];
		}
	}
	for(int i=k;i<=n;i++)
		for(int j=k;j<=m;j++)
		{
			max=-1,min=0x3f3f3f3f;
			for(int p=i-k+1;p<=i;p++)
			{
				max=std::max(max,f1[p][j]);
				min=std::min(min,f2[p][j]);		
			}
			ans=std::min(max-min,ans);
		}
	printf("%d\n",ans);
	return 0;
}
