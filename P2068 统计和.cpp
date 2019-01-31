#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
typedef long long LL;
const int maxn=1e5+5;
int n,w,c[maxn];
void add(int x,LL w)
{
    while(x<=n)
    {
        c[x]+=w;
        x+=lowbit(x);
    }
}
LL ask(int x)
{
    LL ans=0;
    while(x>0)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    cin>>n>>w;
    for(int i=1;i<=w;i++)
    {
        char c;
        LL a,b;
        cin>>c;
        scanf("%lld%lld",&a,&b);
        if(c=='x') add(a,b);
        else printf("%lld\n",ask(b)-ask(a-1));
    }
}