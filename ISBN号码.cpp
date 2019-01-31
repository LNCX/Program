#include<iostream>
using namespace std;
int main()
{
	char a[13];
	cin>>a;
	int ans=a[0]-'0';
	for(int i=2;i<=4;i++) ans+=(a[i]-'0')*i;
	for(int i=6;i<=10;i++) ans+=(a[i]-'0')*(i-1);
	if(ans%11==a[12]-'0'||(ans%11==10&&a[12]=='X')) cout<<"Right"<<endl;
	else 
	{
		for(int i=0;i<12;i++) cout<<a[i];
		if(ans%11!=10)cout<<ans%11<<endl;
		else cout<<'X'<<endl;
	}
}
