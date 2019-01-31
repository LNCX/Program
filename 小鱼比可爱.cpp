#include<iostream>
using namespace std;
int main()
{
	int count=0,a[101],n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
			if(a[i]>a[j]) 
				count++;
		cout<<count<<" ";
		count=0;
	}
}

