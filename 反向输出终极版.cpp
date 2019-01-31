#include<iostream>
using namespace std;
int main()
{
	while(1)
	{
		char char2[100];
		int j;
		cin>>char2;
    	for(j=0;j<=99;j++)
    	if(char2[j]==char2[99])
    	{
    		break;
		}
		for(int i=j-1;i>=0;i--)
		cout<<char2[i];
		cout<<endl;
	}	
}
