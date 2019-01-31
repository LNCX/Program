#include<bits/stdc++.h>
using namespace std;
int a[10005],ans;
int main()
{
	int n,l,t;
    scanf("%d",&n);
	while(n--)
	{
		int i,x=0;
        scanf("%d%d",&i,&l);
        while(scanf("%d",&t)&&t)
            x=max(a[t],x);
        a[i]=x+l;
        ans=max(a[i],ans);
    }
    printf("%d\n",ans);
    return 0;
 } 
