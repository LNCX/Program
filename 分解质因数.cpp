#include<iostream>
using namespace std;
int main()
{
	int x=257885161;
	for(int i=2;i<x;i++)
	if(x%i==0)
	cout<<i<<" ";
}
