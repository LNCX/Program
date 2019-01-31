#include<bits/stdc++.h>
using namespace std;
int get()
{
	int x=0;
	char c=getchar();
	while(c<'0'||'9'<c) c=getchar();
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
int main()
{
	while(1)
	{
		int a=get();
		cout<<a<<endl;
	}
	return 0;
}
