#include<bits/stdc++.h>
using namespace std;
bool prime(int a)
{
	if(a==1) return 0;
	if(a==2||a==3) return 1;
	if(a%6!=1&&a%6!=5) return 0;
	int temp=sqrt(a);
	for(int i=5;i<=temp;i+=6)
		if(a%i==0||a%(i+2)==0) 
			return 0;
	return 1;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; i++)
	{
		int x;
		scanf("%d",&x);
		if(prime(x)) printf("Yes"),cout<<endl;
		else printf("No"),cout<<endl;
		x=0;
	}
}
