#include<bits/stdc++.h>
using namespace std;
int f[300005];
int main()
{
	int m,s,t;
	scanf("%d%d%d",&m,&s,&t);
	for(int i=1;i<=t;i++)
		if(m>=10)	f[i]=f[i-1]+60,m-=10;
		else	f[i]=f[i-1],m+=4;
	for(int i=1;i<=t;i++)
	{
		f[i]=max(f[i],f[i-1]+17);	
		if(f[i]>=s)
		{
			printf("Yes\n%d\n",i);
			return 0; 
		}
	}
	printf("No\n%d\n",f[t]);
}

