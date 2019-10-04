#include<bits/stdc++.h>
#define int long long
using namespace std;
struct line
{
    int l,r;
    bool operator<(const line &k) const
    {
        return l<k.l;
    }
};
set<line>s[3];
void print()
{
    int x=s[1].size(),y=s[2].size();
    
}
signed main()
{
    int n,m,q;
    while(scanf("%d%d%d",&n,&m,&q)!=EOF)
    {
        for(int i=1;i<=2;i++)
            s[i].clear(),s[i].insert((line){0,0});
        s[1].insert((line){m,m}),s[2].insert((line){n,n});
        while(q--)
        {
            
        }
    }
    return 0;
}