#include <iostream>
using namespace std;
string ZS(int p)
{
	int tz=0,i;
	if (p<2)return "no";
	if (p==2) return "yes";
	for (i=2;i*i<=p;i++) if (p%i==0) return "no";
	return "yes";
}
int main ()
{
	int n,a,i;
	cin>>n;
	for (i=0;i<n;i++) {cin>>a;cout<<ZS (a)<<endl;}
	return 0;
}
