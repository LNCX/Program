#include<cstdio>
#include<iostream>
#define max 30
using namespace std;
int n,*ans,count;
bool a[max],b[max],c[max];
void print()
{
	if(count<3){for(int i=1;i<=n;i++) printf("%d ",ans[i]);printf("\n");}
	count++;
}
void search(int i)
{
	if(i==n+1) {print();return;}
	for(int j=1;j<=n;j++)
	{
		if(!a[j]&&!b[i-j+n]&&!c[i+j-1])
		{
			ans[i]=j;
			a[j]=true,b[i-j+n]=true,c[i+j-1]=true;
			search(i+1);
			a[j]=false,b[i-j+n]=false,c[i+j-1]=false;
		}
	}
}
int main()
{
	cin>>n; 
	ans=new int[n+1];
	search(1);
	cout<<count<<endl;
	return 0;
} 
