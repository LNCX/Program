#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int N=3e5+5;
int n,m,k,tot,c[N],ans[N];
inline int read()
{
    int x=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return x;
}
struct fix
{
    int l,r,w,id;
}q[N];
struct node
{
    vector<int>p;
    int v,id;
}a[N],al[N],ar[N];
inline void add(register int x,int w)
{
    while(x<=m)
    {
        c[x]+=w;
        x+=lowbit(x);
    }
}
inline int query(register int x)
{
    register int res=0;
    while(x>0)
    {
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}
inline void update(int l,int r,int w)
{
    if(l>r) update(l,m,w),update(1,r,w);
    else add(l,w),add(r+1,-w);
}
inline void CDQ(int l,int r,int l1,int r1,int l2,int r2)
{
    if(l==r)
    {
        for(register int i=l2;i<=r2;i++)
            ans[a[i].id]=l;
        return;
    }
    int mid=(l+r)>>1,cntql=0;
    for(register int i=l1;i<=r1;i++)
    {
        if(q[i].id<=mid) update(q[i].l,q[i].r,q[i].w),++cntql;
        else break;
    }
    int cntal=0,cntar=0;
    for(register int i=l2;i<=r2;i++)
    {
        int x=0;
        for(auto p:a[i].p)
        {
            x+=query(p);
			if(x>=a[i].v) break;
        }
        if(x<a[i].v) a[i].v-=x,ar[++cntar]=a[i];
        else al[++cntal]=a[i];
    }
    for(register int i=1;i<=cntal;i++) a[l2+i-1]=al[i];
    for(register int i=1;i<=cntar;i++) a[l2+cntal+i-1]=ar[i];
    for(register int i=l1;i<=l1+cntql-1;i++) update(q[i].l,q[i].r,-q[i].w);
    CDQ(l,mid,l1,l1+cntql-1,l2,l2+cntal-1);
    CDQ(mid+1,r,l1+cntql,r1,l2+cntal,r2);
}
int main()
{
    n=read(),m=read();
    for(register int i=1;i<=m;i++)
        a[read()].p.push_back((int)i);
    for(register int i=1;i<=n;i++)
        a[i].v=read(),a[i].id=i;
    k=read();
    for(register int i=1;i<=k;i++)
    {
        int l=read(),r=read(),w=read();
        q[i]=(fix){l,r,w,i};
    }
    CDQ(1,k+1,1,k,1,n);
    for(register int i=1;i<=n;i++)
        ans[i]>k?puts("NIE"):printf("%d\n",ans[i]);
    return 0;
}