#include<iostream>
using namespace std;
int main()
{
	int a=0,b=0,c=0;
	int x=0;
	while(1)
	{
		cin>>a>>b>>c;
		int i;
		for(i=10;i<=100;i++)
		{
			if(i%3==a&&i%5==b&&i%7==c)
			{	
				cout<<"Case "<<x<<": "<<i<<endl;
				break;
			}
		}
		if(i==101)
			cout<<"Case "<<x<<": "<<"No answer"<<endl;	
	} 
	
}
