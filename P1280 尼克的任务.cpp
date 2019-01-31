#include<bits/stdc++.h>
using namespace std;
struct node
{
	int s[10005];
	int t[10005];
	#define s(x) a.s[x]
	#define t(x) a.t[x]
}a;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d%d",&s(i),&t(i));
	
	return 0;
}
