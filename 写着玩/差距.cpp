#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool a[100000];
int sum(int l,int r,char q[])
{
	int sum=0;
	for(int i=l;i<=r;i++)
	{
		sum*=10;
		sum+=q[i]-'0';
	}
	return sum;
} 
int main()
{
	int n1;
	scanf("%d",&n1);
	for(int i=1;i<=n1;i++)
	{
		char x[10];
		scanf("%s",x);
		a[sum(2,5,x)]=true;
	}
	int n2;
	scanf("%d",&n2); 
	for(int i=1;i<n2;i++)
	{
		char x[10];
		scanf("%s",x);
		a[sum(2,5,x)]=false;
	}
	freopen("data.txt","w",stdout);
	for(int i=1;i<=100000;i++)
	if(a[i]) printf("[P%d] ",i);
}

