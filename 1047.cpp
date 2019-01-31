#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		cin>>a[i][j];
	int count1=0,flag1=2,loc1=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			count1+=a[i][j];
		if(count1%2==1)
		{
			loc1=i;
			flag1--;
		}
		if(flag1==0) break;
		count1=0;
	}
	int count2=0,flag2=2,loc2=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			count2+=a[j][i];
		if(count2%2==1)
		{
			loc2=i;
			flag2--;	
		}
		if(flag2==0) break;
		count2=0;
	}
	if(flag1+flag2==4) cout<<"OK"<<endl;
	else if(flag1==1&&flag2==1) cout<<loc1+1<<" "<<loc2+1<<endl;
	else cout<<"Corrupt"<<endl;
}
