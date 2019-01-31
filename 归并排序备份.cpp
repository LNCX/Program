#include<iostream>
using namespace std;
int sort(int a[10],int l, int r);
int main()
{
	int a[3]={10,9,8};
	sort(a,0,2);
	for(int i=0;i<=2;i++)
		cout<<a[i]<<"\t";
	cout<<endl;
}
int sort(int a[10],int l, int r)
{
	int med=a[r]; 
	int count1=0,count2=0;
	int change1[10]={0},change2[10]={0};
	for(int i=l;i<r;i++)
	{
		if(a[i]<med)
		{
			change1[count1]=a[i];
			count1++;
		}
		else if(a[i]>med)
		{
			change2[count2]=a[i];
			count2++;
		}
	}
	a[count1]=med;
	for(int i=l;i<count1;i++)
		a[i]=change1[i];
	for(int i=l;i<count2;i++)
		a[count1+1+i]=change2[i];
	if(count1>1||count2>1)
	{
		sort(a,l,count1-1);
		sort(a,count1+1,r);
	}
	return 0;	
	
}
