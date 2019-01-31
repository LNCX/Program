#include<iostream>
using namespace std;
int sort(int cha[],int x);
int main()
{
	int n=0,m=0,i=0,j=0,x=0,y=0,count=0,control=0;
	int con[2001]={0},size[2001]={0},man[2001]={0};
	while(cin>>n&&cin>>m)
	{
		for(i=0;i<n;i++)
			cin>>size[i];
		sort(size,i);
		for(j=0;j<m;j++)
			cin>>man[j];
		sort(size,j);
		if(i>j)
		{
			con[x]=-1;
			break;
		}	
		else if(i<=j)
		{
			for(y=0;y<i;y++)
			{
				if(size[y]<=man[y+control])	
					count+=man[y+control];
				else
					control++;
			}	
		}
		if(y+control>=n)
			con[x]=-1;
		else
			con[x]=count;
		x++;
	}
	for(int i=0;i<=x;x++)
	if(con[x]!=-1)
		cout<<con[x]<<endl;
	else cout<<"Loowater is doomed"<<endl;
	
}  
int sort(int a[],int x)
{
	int itemp;
	for(int i=0;i<x;i++)
	{
		for(int j=x-1;j>=i;j--)
		{
			if(a[j]<a[j-1])
			{
				itemp=a[j-1];
				a[j-1]=a[j];
				a[j]=itemp;
			}
		}
	}
}
