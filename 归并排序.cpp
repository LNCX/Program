#include<iostream>
using namespace std;
int sort(int a[10],int l, int r);
int main()
{
	int a[10]={10,9,8,7,6,1,2,3,4,5};
	sort(a,0,9);
	for(int i=0;i<10;i++)
		cout<<a[i]<<"\t";
	cout<<endl;
}
int sort(int a[10],int l, int r)
{
	int med=a[l+r/2]; 
	int count1=0,count2=0;
	int change1[10],change2[10];
	for(int i=l;i<r;i++)
	{
		if(a[i]<med)
		{
			change1[count1+l]=a[i];
			count1++;
		}
		else if(a[i]>med)
		{
			change2[count2]=a[i];
			count2++;
		}
	}
	a[count1]=med;
	for(int i=l;i<count1+l;i++)
		a[i]=change1[i];
	for(int i=count1+l+1;i<count2+count1+l;i++)
		a[i]=change2[i];
	if(count1>1) sort(a,l,count1+l);
	if(count2>l) sort(a,count2+count1+1,r);
	return 0;	
}
