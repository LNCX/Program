#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
struct node
{
    unsigned v,p;
    bool operator<(const node &x) const 
    {
        if(p==x.p) return v<x.v;
        else return p<x.p;
    }
}a[N];
int n,m,tot=0,cnt[N],sum;
unsigned ans=0x7fffffff;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int t;
        scanf("%d",&t);
        for(int j=1;j<=t;j++)
        {
            tot++;
            scanf("%d",&a[tot].p);
            a[tot].v=i;
        }
    }
    sort(a+1,a+1+n);
    int l=1,r=0;
    while(l<=n&&r<=n)
    {
        while(sum!=m)
        {
            do
            {
                cnt[a[++r].v]++;
                if(cnt[a[r].v]==1) sum++;
            }while(a[r].p==a[r+1].p);
        }
        ans=min(ans,a[r].p-a[l].p);
        while(sum==m)
        {
            do
            {
                cnt[a[l++].v]--; 
                if(cnt[a[l-1].v]==0) sum--;
            }while(a[l].p==a[l-1].p);
        }
        ans=min(ans,a[r].p-a[l-1].p);
    }
    cout<<ans<<endl;
    return 0;
}