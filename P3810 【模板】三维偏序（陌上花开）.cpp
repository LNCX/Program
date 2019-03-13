#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
const int maxn=1e5+5;
int n,k,tot=1,c[maxn<<1],ans[maxn];
struct point
{
    int x,y,z,w,f;
    bool operator<(const point &a) const 
    {
        if(x!=a.x) return x<a.x;
        if(y!=a.y) return y<a.y;
        else return z<a.z;
    }
    bool operator==(const point &a) const 
    {
        if(x==a.x&&y==a.y&&z==a.z) return true;
        else return false;
    }
}a[maxn],t[maxn];
void fix(int x,int y)
{
    while(x<=k)
    {
        c[x]+=y;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int res=0;
    while(x>0)
    {
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}
void CDQ(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)>>1;
    CDQ(l,mid);CDQ(mid+1,r);
    int p=l,q=mid+1,cnt=l;
    while(p<=mid&&q<=r)
    {
        if(a[p].y<=a[q].y) fix(a[p].z,a[p].w),t[cnt++]=a[p++];
        else a[q].f+=sum(a[q].z),t[cnt++]=a[q++];
    }
    while(p<=mid) fix(a[p].z,a[p].w),t[cnt++]=a[p++];
    while(q<=r) a[q].f+=sum(a[q].z),t[cnt++]=a[q++];
    for(int i=l;i<=mid;i++) fix(a[i].z,-a[i].w);
    for(int i=l;i<=r;i++) a[i]=t[i];
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z),a[i].w=1;
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)
    {
        if(a[i]==a[tot]) a[tot].w++;
        else a[++tot]=a[i];
    }
    CDQ(1,tot);
    for(int i=1;i<=tot;i++) 
        ans[a[i].f+a[i].w-1]+=a[i].w;
    for(int i=0;i<n;i++)
        printf("%d\n",ans[i]);
    return 0;
}