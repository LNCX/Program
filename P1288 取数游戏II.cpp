#include<bits/stdc++.h>
#define judge(x) (x&1)
using namespace std;
int n,s[1000];
int main()
{
	cin>>n;
    for(int i=1;i<=n;i++) 
		scanf("%d",&s[i]);
    int a=0;while(s[++a]);
    int b=0;while(s[n+1-(++b)]);
    if (judge(--a)||judge(--b))  
		printf("YES\n");  
	else printf("NO\n");
}
