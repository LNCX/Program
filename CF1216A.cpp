#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
char c[N];
int n,a,ans;
int main()
{
	scanf("%d%s",&n,c+1);
	for(int i=1;i<=n;i++)
	{
		if(c[i]=='a') a++;
		if(i%2==0)
		{
			if(a*2>i)
			{
				c[i]='b';
				a--,ans++;
			}
			else if(a*2<i)
			{
				c[i]='a';
				a++,ans++;
			}
		}
	}
	printf("%d\n%s",ans,c+1);
	return 0;
}