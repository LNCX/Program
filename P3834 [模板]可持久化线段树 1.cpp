#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,q,m,cnt;
int a[maxn],b[maxn],t[maxn];
int ch[maxn<<5][2],sum[maxn<<5];
int build(int l,int r)
{
    int rt=++cnt,mid=(l+r)>>1;
    if(l==r) return rt;
    ch[rt][0]=build(l,mid);
    ch[rt][1]=build(mid+1,r);
    return rt;
}
int update(int pre,int l,int r,int x)
{
    int rt=++cnt,mid=(l+r)>>1;
    ch[rt][0]=ch[pre][0],ch[rt][1]=ch[pre][1],sum[rt]=sum[pre]+1;
    if(l==r) return rt;
    if(x<=mid) ch[rt][0]=update(ch[pre][0],l,mid,x);
    else ch[rt][1]=update(ch[rt][1],mid+1,r,x);
    return rt;
}
int query(int u,int v,int l,int r,int k)
{
    if(l==r) return l;
    int x=sum[ch[v][0]]-sum[ch[u][0]],mid=(l+r)>>1;
    if(x>=k) return query(ch[u][0],ch[v][0],l,mid,k);
    else return query(ch[u][1],ch[v][1],mid+1,r,k-x);
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+1+n);
    m=unique(b+1,b+1+n)-b-1;
    t[0]=build(1,m);
    for(int i=1;i<=n;i++)
    {
        int x=lower_bound(b+1,b+1+m,a[i])-b;
        t[i]=update(t[i-1],1,m,x);
    }
    while(q--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        printf("%d\n",b[query(t[x-1],t[y],1,m,z)]);
    }
    return 0;
}