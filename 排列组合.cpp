#include<iostream>
using namespace std;
int f(int x)
{
	int sum=1;
	for(int i=1;i<=x;i++)
		sum*=i;
	return sum;
}
int c(int n,int r)
{
	cout<<"×éºÏ£º"<<f(n)/(f(r)*f(n-r))<<endl;
}
int p(int n,int r)
{
	cout<<"ÅÅÁÐ£º"<<f(n)/f(n-r)<<endl;
}
int main()
{
	int n,r,flag=1;
	while(1)
	{
		cin>>n>>r;
		if(n==0&&r==0) flag=-flag;
		if(flag==1) c(n,r);
		else p(n,r); 	
	} 
}
