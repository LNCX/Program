#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[20];
	cin>>s;
	int flag=1;
	for(int i=0;i<strlen(s);i++)
	{
		if('0'<=s[i]&&s[i]<='9'&&i!=0) continue;
		else if(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z')||s[i]=='_') continue;
		else {flag=0;break;}
		
	}
	if(flag) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
}
