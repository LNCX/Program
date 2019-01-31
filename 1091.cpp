#include<iostream>
using namespace std;
int main()
{
	int n,q;
	cin>>n>>q;
	struct picture
	{
		char shape;
		float a;
		float b;
	}l[n];
	for(int i=0;i<n;i++)
	{
		cin>>l[i].shape;
		cin>>l[i].a;
		if(l[i].shape=='R')cin>>l[i].b;
	}
	int que[q];
	for(int i=0;i<q;i++) cin>>que[i];
	for(int i=0;i<q;i++)
	{
		switch ((int)l[que[i]-1].shape)
		{
			case (int)'T': cout<<"Triangle "<<l[que[i]-1].a;break;
			case (int)'C': cout<<"Circle "<<l[que[i]-1].a;break;
			case (int)'R': cout<<"Rectangle "<<l[que[i]-1].a<<" "<<l[que[i]-1].b;break;
			default:break;
		}
		cout<<endl;
	}
}
