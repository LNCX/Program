#include<iostream>
using namespace std;
struct student
{
	int a,b,c,d,e;
}k[1002];
int ka,kb,kc,kd,ke,n,m,id,s;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>k[i].a
		   >>k[i].b
		   >>k[i].c
		   >>k[i].d
		   >>k[i].e;
	for(int i=0;i<m;i++)
	{
		cin>>ka>>kb>>kc>>kd>>ke>>id;
		s=ka*k[id-1].a+
		  kb*k[id-1].b+
		  kc*k[id-1].c+
		  kd*k[id-1].d+
		  ke*k[id-1].e;
		cout<<s<<" ";
	}
	return 0;
}


