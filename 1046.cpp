#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n=0,s=0;
	char a[250];
	cin>>a;
	int la=strlen(a);
	for (int i=0;i<la;i++)
	{
		if (a[i]!='+') n=n*10+a[i]-'0';
		else {s+=n;n=0;}
		if (i==la-1)
		s+=n;
	}
	  cout<<s;
	  return 0;
}
