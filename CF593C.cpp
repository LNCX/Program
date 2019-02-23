#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
int n,x[maxn],y[maxn],r[maxn];
void solve(int *x)
{
    int t, w=0;
	for(int i=1;i<=n;i++)
        putchar('(');
	for(int i=1;i<=n;i++) 
    {
		int t=x[i]+1>>1;
		if(i>1) putchar('(');
		printf("%d*((1-abs((t-%d)))+abs((abs((t-%d))-1))))",t,i-1,i-1);
		if(i>1) putchar(')');
		if(i!= n) putchar('+');
	}
	puts("");
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&x[i],&y[i],&r[i]);
    solve(x),solve(y);
    return 0;
}