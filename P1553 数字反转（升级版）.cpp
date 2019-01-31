#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a=0;
	char s[50];
	scanf("%s",s+1);
	int len=strlen(s)-1;
	for(int i=1;i<=len;i++)
		if(!('0'<=s[i]&&s[i]<='9'))	
		{
			a=i;
			break;
		}
	if(a==0)
	{
		while(s[len]=='0'&&len>1) len--;
		for(int i=len;i>=1;i--)
			printf("%c",s[i]);
		cout<<endl;
	}
	else
	{
		int b=a-1;
		while(s[b]=='0'&&b>1) b--;
		for(int i=b;i>=1;i--)
			printf("%c",s[i]);
		printf("%c",s[a]);
		if(s[a]=='%') return 0;
		b=a+1;
		while(s[len]=='0'&&len>b&&s[a]!='!') len--;
		while(s[b]=='0'&&b<len) b++;
		for(int i=len;i>=b;i--)
			printf("%c",s[i]);
		cout<<endl;
	}
}
