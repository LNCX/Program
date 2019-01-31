#include<iostream>
using namespace std;
int date(int year,int month,int day)
{
	int count=0;
	if(month>12||day>31)
		cout<<"Error"<<endl;
	else
	{
		int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		if(year%4==0&&year%100!=0||year%400==0)
			a[1]=29;
		for(int i=0;i<=month-2;i++)
		{
			count+=a[i]; 
		}
	}
	return count;
}
int main()
{
	int k;
	cin>>k;
	while(k--)
	{
		int a,c,e;
		cin>>a>>c>>e;
		int m=date(a,c,e);
		int b,d,f;
		cin>>b>>d>>f;
		int n=date(b,d,f);
		int count=0;
		for(int i=a;i<=b;i++)
		{
			if(i%4==0&&i%100!=0||i%400==0)
				count+=366;
			else count+=365;	
		}
		count-=m;
		if(b%4==0&&b%100!=0||b%400==0)
			count=count-366+n;
		else count=count-365+n;
		cout<<"The rest of the days are "<<count+1<<"days"<<endl;
	}
}
