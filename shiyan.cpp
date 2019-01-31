#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char n[100];
	cin>>n;
	cout<<strlen(n)<<endl;
	memset(n,' ',sizeof(n));
	cout<<strlen(n)<<endl;
}
