#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int n,k;
int main()
{
    scanf("%d%d%s",&n,&k,s+1);
    int x=1,y=1,z=n-k-1;
    for(int i=2;i<=n&&s[i]==s[i-1];i++) x++;
    for(int i=n-1;i>1&&s[i]==s[i+1];i--) y++;
    if(x+k>=n||y+k>=n||(s[1]==s[n]&&x+y+k>=n)) puts("tokitsukaze");
    else if(s[1]!=s[n]&&x>=z&&y>=z&&k>=z) puts("quailty");
    else puts("once again");
    return 0;
}