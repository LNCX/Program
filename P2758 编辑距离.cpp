#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int f[maxn][maxn];
char a[maxn],b[maxn];
int main()
{
	scanf("%s%s",a+1,b+1);
	int lena=strlen(a+1),lenb=strlen(b+1);
	for(int i=0;i<=lena||i<=lenb;i++)
		f[i][0]=f[0][i]=i;
	for(int i=1;i<=lena;i++)
		for(int j=1;j<=lenb;j++)
		{
			int k=1;
			if(a[i]==b[j]) k=0;
			f[i][j]=min(min(f[i-1][j],f[i][j-1])+1,f[i-1][j-1]+k);
		}
	cout<<f[lena][lenb]<<endl;
	return 0;
}
