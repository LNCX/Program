#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+5;
map< int,pair<char,int> >m;
int main()
{
    LL n,q;
    scanf("%lld%lld",&n,&q);
    m[0]=make_pair('U',0);
    m[n+1]=make_pair('L',0);
    while(q--)
    {
        LL x,y;
        string s;
        scanf("%lld%lld",&x,&y);
        cin>>s;
        auto it=m.lower_bound(x);
        if(it->first==x)
        {
            puts("0");
            continue;
        }
        if(s[0]=='L') it--;
        LL ans=abs((it->first)-x);
        if(it->second.first==s[0])
            ans+=it->second.second;
        printf("%lld\n",ans);
        m[x]=make_pair(s[0],ans);
    }
    return 0;
}