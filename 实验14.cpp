#include<bits/stdc++.h>
using namespace std;
int fun(int n,int minNum,int maxNum)
{
	int tot,i;
	if(n==0) return 1;
	tot=0;
	for(i=minNum;i<=maxNum;i++)
		tot+=fun(n-1,i+1,maxNum);
	return tot;
}
int main()
{
	int n,m;
	cin>>n>>m;
	cout<<fun(m,1,n)<<endl;
	return 0;
}
