#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std; 
int main()
{
	int a=98,b=109 ;
	for(int i=1;i<=5;i++)
		cout<<rand()%(b-a+1)+a<<" ";
}
