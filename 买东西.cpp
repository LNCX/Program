#include<iostream>
using namespace std;
int main()
{
	while(1)
	{
		int a;
		cin>>a;
		if(3*a*0.88>(a-a/8)*3)
		cout<<"天街"<<endl;
		else if(3*a*0.88<(a-a/8)*3)
			cout<<"银泰"<<endl;
		else
			cout<<"爱怎么买就怎么买"<<endl;
 
	} 
} 
