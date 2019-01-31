#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		char s[100005];
		scanf("%s",s);
		for(int i=0;i<strlen(s);i++)
		{
			if(i%2==0&&s[i]!='+') ans++;
			if(i%2==1&&s[i]!='-') ans++;
		}
		printf("%d\n",min(ans,(int)strlen(s)-ans));
	}
	return 0;
}
