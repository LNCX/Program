#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
char s[N];
int n,maxx=-1,ans,w[N];
int main()
{
    scanf("%s%d",s+1,&n);
    for(int i=0;i<26;i++)
    {
        scanf("%d",&w[i]);
        maxx=max(w[i],maxx);
    }
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
        ans+=w[s[i]-'a']*i;
    for(int i=len+1;i<=len+n;i++)
        ans+=maxx*i;
    cout<<ans<<endl;
    return 0;
}