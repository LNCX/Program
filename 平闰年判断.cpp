#include<iostream>
using namespace std;
int main()
{
	int a; 
	cin>>a;
	if(a%4==0&&a%100!=0||a%400==0)
	{
		cout<<a<<"是闰年"<<endl; 
	}
	else
		cout<<a<<"不是闰年"<<endl;
}
