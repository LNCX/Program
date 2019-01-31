#include<bits/stdc++.h>
using namespace std;
int f(int n)
{
	if(n==1) return 0;
	else if(n==2||n==3) return 1;
	else return f(n-3)+2*f(n-2)+f(n-1);
}
int main()
{
	int n;
	cin>>n;
	cout<<f(n)<<endl;
}

