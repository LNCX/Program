#include<iostream>
using namespace std;
struct peo
{
	int name;
	int score;
}a[5000];
int sort(int n,int m)
{
	int count=0;
	for(int i=n-1;i>=0;i--)
	for(int j=0;j<=i;j++)
	if(a[j].score<a[j+1].score)
	{
		peo temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i].score>=a[(int)(m*1.5)-1].score) count++;
		else break;
	}
	return count;
}
int main()
{
	int n,m,count=0;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i].name>>a[i].score;
	int x=sort(n,m);
	cout<<a[(int)(m*1.5)].score<<" "<<x<<endl;
	for(int i=0;i<=x-1;i++)
	{
		if(a[i].score==a[i+1].score) count++;
		else if(count)
		{
			for(int j=i;j>=i-count;j--)
			for(int k=i-count;k<=j;k++)
			if(a[k].score==a[k+1].score&&a[k].name>a[k+1].name)
			{
				peo temp=a[k];
				a[k]=a[k+1];
				a[k+1]=temp;
			}
		}
	}
	for(int i=0;i<=x-1;i++)
		cout<<a[i].name<<" "<<a[i].score<<endl;	
}

