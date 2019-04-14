#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%d",&a);
		if(a==0) continue;
		if(i!=1&&a>0) printf("+");
		if(a==1) printf("x^%d",n-i+1);
		else if(a==-1) printf("-x^%d",n-i+1);
		else printf("%dx^%d",a,n-i+1);
	}
	cin>>a;
	if(a!=0)
	{
		if(a>0) printf("+");
		if(a==1) printf("x");
		else if(a==-1) printf("-x");
		else printf("%dx",a);
	}
	cin>>a;
	if(a>0) cout<<"+"<<a<<endl;
	else if(a<0) cout<<a<<endl; 
	return 0;
}

