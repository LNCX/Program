#include <bits/stdc++.h>
using namespace std;
int main()
{
	char a[10000],x;
	int mode=0,w=0;
	float ans[4]= {0,0,0,0},cache=-1,vx;
	float dx[3]= {1,1,-1};
	cin>>a;
	int i=0;
	for(int j=0;; j++)
	{
		if(a[j]<='z'&&a[j]>='a')
		{
			x=a[j];
			break;
		}
	}
	do
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			if(cache==-1)cache++;
			cache*=10,cache+=a[i]-'0';
		}
		if(a[i]==x)
		{
			if(mode==-1)mode=0;
			else
			{
				if(cache==-1)ans[w+2]+=dx[mode]*1;
				else if(cache)ans[w+2]+=dx[mode]*cache;
				cache=-1;
				mode=-1;
			}
			i++;
			continue;
		}
		switch (a[i])
		{
				break;
			case '-':
				if(mode==-1)mode=2;
				else
				{
					if(cache!=-1)ans[w]+=dx[mode]*cache;
					cache=-1;
					mode=2;
				}
				break;
			case '+':
				if(mode==-1)mode=1;
				else
				{
					if(cache!=-1)ans[w]+=dx[mode]*cache;
					cache=-1;
					mode=1;
				}
				break;
			case '=':
				if(mode==-1)mode=0;
				else
				{
					ans[w]+=dx[mode]*cache;
					cache=-1;
					mode=0;
					w++;
				}
				break;
		}
		i++;
	}
	while(a[i]);
	if(mode!=-1)ans[w]+=dx[mode]*cache;
	printf("%c",x);
	float aa=(ans[1]-ans[0]),ab=(ans[2]-ans[3]);
	if(!int(aa))printf("=0.000");
	else printf("=%0.3f",aa/ab);
}
