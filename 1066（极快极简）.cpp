#include<iostream>
using namespace std;
int pri(int a)
{
	int flag=1;
	if(a%2==0) flag=0;
	if(flag) for(int i=3;i<a;i++) if(a%i==0){flag=0;break;}
	return flag;
}
int main()
{
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)
		if(pri(i)&&pri(i+2))
			cout<<i<<" "<<i+2<<endl;
}

