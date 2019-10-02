#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,a[N],b[N],cnt[N],ans;
char s[N];
int main()
{
    scanf("%s",&s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++)
        cnt[s[i]-'a']++,b[s[i]-'a']=i;
    int l=1,r=0,mx=0; 
    for(int i=1;i<=n;i++)
    {
        r=max(r,b[s[i]-'a']);
        mx=max(mx,cnt[s[i]-'a']);
        if(i==r)
        {
            ans=max(ans)
            l=r+1,r=mx=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}