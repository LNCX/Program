#include<bits/stdc++.h>
using namespace std;
int a[105][3],f[105][20][20];
//用f[i][j][k]表示处理到i行,当前选了j个矩阵
//0空出这一行；1选左边；2选右边；3两边都要,分开；4两边都要，不分开；
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d",&a[i][j]);
	if(m==1)
	{
		for(int i=1; i<=n; i++)
			for(int j=1; j<=k; j++)
			{
				f[i][j][1]=max(f[i-1][j][1],f[i-1][j-1][0])+a[i][1];
				f[i][j][0]=max(f[i-1][j][1],f[i-1][j][0]);
			}
		printf("%d",max(f[n][k][0],f[n][k][1]));
		return 0;
	}
	memset(f,-0x3f3f3f3f,sizeof(f));
	for(int i=0; i<=n; i++)
		for(int j=0; j<=k; j++)
			f[i][j][0]=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=k; j++)
		{
			//case 0
			f[i][j][0]=max(max(f[i-1][j][0],f[i-1][j][1]),max(f[i-1][j][2],f[i-1][j][3]));
			f[i][j][0]=max(f[i][j][0],f[i-1][j][4]);
			//case 1
			f[i][j][1]=max(max(f[i-1][j-1][0],f[i-1][j][1]),max(f[i-1][j-1][2],f[i-1][j][3]));
			f[i][j][1]=max(f[i][j][1],f[i-1][j-1][4])+a[i][1];
			//case 2
			f[i][j][2]=max(max(f[i-1][j-1][0],f[i-1][j-1][1]),max(f[i-1][j][2],f[i-1][j][3]));
			f[i][j][2]=max(f[i][j][2],f[i-1][j-1][4])+a[i][2];
			//case 3
			f[i][j][3]=max(f[i-1][j-1][1],max(f[i-1][j-1][2],f[i-1][j][3]))+a[i][1]+a[i][2];
            if(j>=2) f[i][j][3]=max(f[i][j][3],f[i-1][j-2][4]+a[i][1]+a[i][2]);
            //case 4
			f[i][j][4]=max( max(f[i-1][j-1][0],f[i-1][j-1][1]),max(f[i-1][j-1][2],f[i-1][j-1][3]))+a[i][1]+a[i][2];
            f[i][j][4]=max(f[i][j][4],f[i-1][j][4]+a[i][1]+a[i][2]);
		}
	printf("%d\n",max(max(max(f[n][k][0],f[n][k][1]),max(f[n][k][2],f[n][k][3])),f[n][k][4]));
	return 0;
}

