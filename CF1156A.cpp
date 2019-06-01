#include<bits/stdc++.h>
using namespace std;
int n,a[105],s;
int main()
{
	scanf("%d%d",&n,&a[1]);
	for(int i=2;i<=n;i++)
    {
		scanf("%d",&a[i]);
		if(a[i]+a[i-1]==5) return puts("Infinite"),0;
		if(a[i]==1) s+=a[i-1]+1;
		else s+=a[i]+1-(a[i]==2&&a[i-2]==3);
	}
	printf("Finite\n%d",s);
}