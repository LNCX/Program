#include<bits/stdc++.h>
using namespace std;
const int maxn=30000005;
int ans[maxn];
int main()
{
	for(int c=1;c<=(maxn>>1);c++)
        for(int a=c*2;a<=maxn;a+=c)
        {
            int b=a-c;
            if(c==(a^b)) ans[a]++;
        }
    for(int i=2;i<=maxn;i++) 
		ans[i]+=ans[i-1];
	int t;
	scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
    	int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",i,ans[n]);
    }
    return 0;
}

