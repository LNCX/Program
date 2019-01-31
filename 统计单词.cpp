#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int min=200;
	char m[200],n[200];
	char *x=n;
	while(1)
	{
		cin>>n;
		if(strlen(n)<min) 
		{
			min=strlen(n);
			x=n;
		}
		if(n[strlen(n)-1]=='.') break;
	}
	cout<<x<<endl;
}
