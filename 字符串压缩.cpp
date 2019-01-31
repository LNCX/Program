#include<iostream>
#include<cstring>
using namespace std; 
void print(char c)
{
	if('0'<=c&&c<='9') cout<<c-'0'<<endl;
}
int main()
{
	char a[255];
	cin>>a;
	int count=0,l=0;
	for(int i=0;i<=strlen(a);i++)
	{
		if(a[l]==a[i]) count++;
		else
		{
			cout<<count<<a[l];
			
			l=i;
			count=1;
		}
	}
}
