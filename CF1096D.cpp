#include <bits/stdc++.h>
using namespace std;
string s;
long long n,a,b,c,d;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
    {
		int h;
		cin>>h;
		if(s[i]=='h') a+=h;
		else if(s[i]=='a') b=min(a,b+h);
		else if(s[i]=='r') c=min(b,c+h);
		else if(s[i]=='d') d=min(c,d+h);
	}
	cout<<d<<endl;
    return 0;
}