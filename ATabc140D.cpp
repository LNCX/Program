#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[N];
int n,k,ans;
int main()
{
    scanf("%d%d%s",&n,&k,s+1);
    for(int i=1;i<=n;i++)
        if((s[i]=='L'&&s[i-1]=='L')||(s[i]=='R'&&s[i+1]=='R'))
            ans++;
    ans+=2*k;
    printf("%d\n",min(ans,n-1));
    return 0;
}