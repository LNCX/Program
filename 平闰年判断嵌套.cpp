#include<iostream>
using namespace std;
int main()
{
	int year;
	cin>>year;
	int flag=1;
	if(year%4==0)if(year%100==0)if(year%400!=0)
	flag=0; 
	else flag=0;
	if(flag)
		cout<<year<<"������"<<endl;
	else
		cout<<year<<"��������"<<endl;
}
