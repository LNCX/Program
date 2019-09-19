#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin>>s;
	char maxx='z';
	for(auto c:s)
    {
		puts(maxx>=c?"Mike":"Ann");
		maxx=min(maxx,c);
	}
	return 0;
}