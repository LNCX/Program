#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool flag=true;
	int ans=0;
	char s[256];
	cin>>s;
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i]=='(') ans++;
		if(s[i]==')') ans--;
		if(ans<0){flag=false;break;}
	}
	cout<<(flag&&ans==0?"YES":"NO")<<endl;
	return 0;
}

