#include<bits/stdc++.h>
using namespace std;
int a[105][3],f[105][20][20];
//��f[i][j][k]��ʾ����i��,��ǰѡ��j������
//0�ճ���һ�У�1ѡ��ߣ�2ѡ�ұߣ�3���߶�Ҫ,�ֿ���4���߶�Ҫ�����ֿ���
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

