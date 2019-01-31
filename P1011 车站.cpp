#include<bits/stdc++.h>
using namespace std;
int f[25]={0,1,1};
int main()
{
	int n,a,m,x,b;
	scanf("%d%d%d%d",&a,&n,&m,&x);
	for(int i=3;i<n;i++)
		f[i]=f[i-1]+f[i-2];
	b=(m-f[n-3]*a-a)/(f[n-2]-1);
	if(x==1)
		cout<<a<<endl;
	else cout<<(f[x-2]+1)*a+(f[x-1]-1)*b<<endl;
	return 0;
}
