#include<bits/stdc++.h>
using namespace std;
typedef long long  LL;
const int N=1050;
struct node
{
    int t,a,b;
}id[N*10];
int t[N],ti[N],sum[N],dis[N],g[N],n,m,k;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<n;i++)
        scanf("%d",&dis[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&id[i].t,&id[i].a,&id[i].b);
        t[id[i].a]=max(t[id[i].a],id[i].t);
        sum[id[i].b]++;
    }
    for(int i=2;i<=n;i++)
        sum[i]+=sum[i-1];
    for(int i=1;i<=n;i++)
        ti[i]=max(ti[i-1],t[i-1])+dis[i-1];
    int ans=0;
    for(int i=1;i<=m;i++)
        ans+=ti[id[i].b]-id[i].t;
    while(k)
    {
        g[n-1]=n;
        for(int i=n-2;i>0;i--)
        {
            if(ti[i+1]>t[i+1])
                g[i]=g[i+1];
            else
                g[i]=i+1;
        }
        int pos=0,ma=0;
        for(int i=1;i<n;i++)
            if(dis[i]&&(sum[g[i]]-sum[i])>ma)
            {
                ma=sum[g[i]]-sum[i];
                pos=i;
            }
        if(!ma)
            break;
        k--;
        dis[pos]--;
        ans-=ma;
        for(int i=1;i<=n;i++)
            ti[i]=max(ti[i-1],t[i-1])+dis[i-1];
    }
    printf("%d\n",ans);
    return 0;
}