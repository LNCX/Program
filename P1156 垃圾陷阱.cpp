#include<bits/stdc++.h>
using namespace std;
int d,n,ans=0;
int f[105];
struct waste
{
	int t, g, h;
} a[105];
bool cmp(waste a, waste b)
{
	return a.g < b.g;
}
int main()
{
	cin >> d >> n;
	for(int i=1; i<=n; i++)
		cin >> a[i].g >> a[i].t >> a[i].h;
	sort(a+1, a+n+1, cmp);
	memset(f,0x7fffffff,sizeof(f));
	f[0] = 10;
	for(int i=1; i<=n; i++)
		for(int j=d; j>=0; j--)
		{
			if(f[j] < a[i].g) continue;
			if(a[i].h+j >= d)
				printf("%d\n",a[i].g),exit(0);
			f[j+a[i].h]=max(f[j+a[i].h],f[j]);
			f[j]+=a[i].t;
		}
	printf("%d\n",f[0]);
	return 0;
}
