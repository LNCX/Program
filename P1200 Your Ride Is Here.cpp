#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	char a[10],b[10];
	int ansa=1,ansb=1;
	cin>>a>>b;
	for(int i=0;i<strlen(a);i++) ansa*=(a[i]-64);
	for(int i=0;i<strlen(b);i++) ansb*=(b[i]-64);
	if((ansa%47)==(ansb%47)) cout<<"GO"<<endl;
	else cout<<"STAY"<<endl;
}
