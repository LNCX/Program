#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int ans=0;
int a[N],b[N];
char s[N],t[N];
int main()
{
    scanf("%s%s",s+1,t+1);
    int n=strlen(s+1),m=strlen(t+1);
    for(int i=1,j=1;i<=n;i++)
        if(s[i]==t[j])
        {
            a[j]=i;
            ans=max(a[j]-a[j-1]-1,ans);
            if(++j>m) break;
        }
    ans=max(n-a[m],ans);
    for(int i=n,j=m;i>=1;i--)
    {
        if(s[i]==t[j])
        {
            b[j]=i;
            ans=max(b[j+1]-b[j]-1,ans);
            if(--j<1) break;
        }
    }
    ans=max(ans,b[1]-1);
    for(int i=1;i<m;i++)
        ans=max(b[i+1]-a[i]-1,ans);
    cout<<ans<<endl;
    return 0;
}