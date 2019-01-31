#include<bits/stdc++.h>
using namespace std;
const int inf=0x7fffffff;
const int maxn=55;
int num[maxn<<1],sta[maxn<<1];
int n,m,cnt,a[105],f[105][maxn+5][maxn+5];
void init()
{
	for(int i=0;i<(1<<m);i++)//枚举状态
		if(!((i<<1)&i||(i<<2)&i||(i>>2)&i||(i>>1)&i))
		{
			int sum=0;
			for(int k=0;k<n;k++)
				if((1<<k)&i) sum++;
			num[++cnt]=sum;
			sta[cnt]=i;
			if(!(i&a[1])) f[1][cnt][0]=num[cnt];
		}
}
void DP()
{
	for(int i=1;i<=cnt;++i)//枚举第一行状态 
        for(int j=1;j<=cnt;++j)//枚举第二行状态 
            if(((sta[i]&sta[j])==0)&&((sta[j]&a[2])==0))  
				f[2][j][i]=max(f[2][j][i],f[1][i][0]+num[j]);
	for(int i=3;i<=n;i++)//f[i][j][k]=max{f[i-1][k][t]}+num(i,j) | j,k,t互相不冲突 
		for(int j=1;j<=cnt;j++)
			if(!(a[i]&sta[j]))
				for(int k=1;k<=cnt;k++)
					if(!(sta[j]&sta[k]))
						for(int t=1;t<=cnt;t++)
							if(!(sta[k]&sta[j]))
								f[i][j][k]=max(f[i-1][k][t]+num[j],f[i][j][k]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x=0;
		char s[15];
		scanf("%s",s);
		for(int j=0;j<strlen(s);j++)
		{
			x=x<<1;
			if(s[j]=='H') x++;//状态压缩,反着储存
		}
		a[i]=x;
	}
	init();
	DP();
	int ans=-inf;
	for(int j=1;j<=cnt;j++)
		for(int k=1;k<=cnt;k++)
			ans=max(ans,f[n][j][k]);
	cout<<ans<<endl;
	return 0;
}
