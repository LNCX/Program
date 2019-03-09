#include<bits/stdc++.h>
using namespace std;
int n,len1,len2,ans;
string s;
int main()
{	
	cin>>n;
	getline(cin,s),getline(cin,s);
	while(len1<s.size())
	{
		len2=len1+n-1;
		while(len2>len1)
        if(s[len2]=='.'||s[len2]=='?'||s[len2]=='!')
        {
            len1=len2+2;
            break;
        }
        else len2--;
		if(len2==len1) return puts("Impossible"),0;
		ans++;
	}
	cout<<ans<<endl;
}