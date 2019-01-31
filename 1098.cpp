#include<iostream>
#include<cstring>
using namespace std;
int print(long long sum,long long div)
{
	long long r=sum%div;
	while(r)
	{
		sum=div;
		div=r;
		r=sum%div;
	}
	return div;
}
int result(char a[10000],int &i)
{
	i++;
	int count=0;
	while(a[i]!='='&&a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/')
	{
		count*=10;
		count+=a[i]-'0';
		i++;
	}
	i--;
	return count;
}
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		char a[10000];
		cin>>a;
		long long sum=0,div=1; 
		int i=-1;
		sum+=result(a,i);
		for(;i<strlen(a);i++)
		switch(a[i])
		{
			case '+':sum+=result(a,i)*div;break;
			case '-':sum-=result(a,i)*div;break;
			case '*':sum*=result(a,i);break;
			case '/':div*=result(a,i);break;
		}
	int q=print(sum,div);
	if(div/q<0){div=-div;cout<<"-";}
	cout<<sum/q<<"/"<<div/q<<endl;
	}
}
