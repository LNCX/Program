#include<iostream>
using namespace std;
int main()
{
	int i,j,n,x,ans=0;
	cin>>n>>x;
	for(i=1;i<=n;i++)
	{
		j=i;
		while(j>0)
		{
			if(j%10==x) ans++;
			j/=10;
		}	
	} 
	cout<<ans<<endl; 
}
