#include<bits/stdc++.h>
using namespace std;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int n,m;
	cin>>n>>m;
	if(n%4==0&&n%100!=0||n%400==0) a[2]+=1;
	cout<<a[m]<<endl;
}

