#include<iostream>
using namespace std;
int main()
{
	while(1)
	{
		int a;
		cin>>a;
		if(3*a*0.88>(a-a/8)*3)
		cout<<"���"<<endl;
		else if(3*a*0.88<(a-a/8)*3)
			cout<<"��̩"<<endl;
		else
			cout<<"����ô�����ô��"<<endl;
 
	} 
} 
