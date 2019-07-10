#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
typedef long long ll;
const ll maxn=1e5+5,qy=1e8-3;
struct node
{
    int x,y;
    bool operator<(const node &k) const
    {
        return x<k.x;
    } 
}a[maxn],b[maxn];
int n,r[maxn];
ll ans,c[maxn];
void update(int x,int y)
{
    while(x<=n)
    {
        c[x]+=y;
        x+=lowbit(x);
    }
}
ll sum(int x)
{
    ll res=0;
    while(x>0)
    {
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].x);
        a[i].y=i;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&b[i].x);
        b[i].y=i;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
        r[a[i].y]=b[i].y;
    for(int i=1;i<=n;i++)
    {
        (ans+=sum(n)-sum(r[i]))%=qy;
        update(r[i],1);
    }
    cout<<ans%qy<<endl;
    return 0;
}