#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=805,inf=0x3f3f3f3f;
struct node
{
    int u,v;ll w;
    bool operator<(const node k) const
    {
        return w<k.w;
    }
}a[N];
ll dis[M][M];
bitset<N>vis;
map<int,int>ma;
int head[N],tot,cnt;

int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++)
        scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
    sort(a+1,a+1+m);
    memset(dis,inf,sizeof(dis));
    for(int i=1;i<=min(m,k);i++)
    {
        if(!ma.count(a[i].u)) ma[a[i].u]=++cnt;
        if(!ma.count(a[i].v)) ma[a[i].v]=++cnt;
        dis[ma[a[i].u]][ma[a[i].v]]=dis[ma[a[i].v]][ma[a[i].u]]=a[i].w;
    }
    for(int k=1;k<=cnt;k++)
        for(int i=1;i<=cnt;i++)
            for(int j=1;j<=cnt;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    vector<ll>v;
    for(int i=1;i<=cnt;i++)
        for(int j=i+1;j<=cnt;j++)
            v.push_back(dis[i][j]);
    sort(v.begin(),v.end());
    printf("%lld\n",v[k-1]);
    return 0;
}