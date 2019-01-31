#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	while(1)
	{
		char s[100];
		cin>>s;
		for(int i=strlen(s)-1;i>=0;i--)
		cout<<s[i];
		cout<<endl;

	}
}
