#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
typedef long long ll;
const int N=5e5+5;
ll c[N],now,ans[N];
int n,m,a[N],blg[N],block,maxn,p[N];
const int BUFSIZE=1 << 20;
char ibuf[BUFSIZE],*is=ibuf,*it=ibuf;
inline char getch()
{
    if(is==it) it=(is=ibuf)+fread(ibuf,1,BUFSIZE,stdin);
    return is==it?EOF:*is++;
}
void read(){}
template<typename T,typename... Ts>
inline void read(T &arg,Ts&... args)
{
    T x=0,f=1;
    char c=getch();
    while(!isdigit(c)){if(c=='-') f=-1;c=getch();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c-'0');c=getch();}
    arg=x*f;
    read(args...);
}
struct node
{
    int l,r,id;
    friend bool operator<(const node & a,const node &b)
    {
        return (a.l/block)^(b.l/block)?a.l<b.l:(((a.l/block)&1)?a.r<b.r:a.r>b.r);
    }
}q[N];
inline void update(int x,int y)
{
    int u=x;  
    while(u<=maxn)
    {
        p[u]+=y,c[u]+=(ll)x*y;
        u+=lowbit(u);
    }
}
inline int num(int x)
{
    int res=0;
    while(x>0)
    {   
        res+=p[x];
        x-=lowbit(x);
    }           
    return res;
}
inline ll ask(int x)
{
    ll res=0;
    while(x>0)
    {   
        res+=c[x];
        x-=lowbit(x);
    }           
    return res;
}
inline void add(int x)
{
    x=a[x];
    now+=(ll)(num(x-1)+1)*x;
    now+=(ll)ask(maxn)-ask(x);
    update(x,1);
}
inline void del(int x)
{
    x=a[x];
    now-=(ll)(num(x-1)+1)*x;
    now-=(ll)ask(maxn)-ask(x);
    update(x,-1);
}
inline void moque()
{
    register int l=1,r=0;now=0;
    for(int i=1;i<=m;i++)
    {
        int ql=q[i].l,qr=q[i].r;
        while(ql<l) add(--l);
        while(ql>l) del(l++);
        while(qr<r) del(r--); 
        while(qr>r) add(++r);
        ans[q[i].id]=now;
    }
}
signed main()
{   
    read(n,m);
    for(int i=1;i<=n;i++)
        read(a[i]),maxn=max(maxn,a[i]);
    for(int i=1;i<=m;i++)
    {
        read(q[i].l,q[i].r);
        q[i].id=i;
    }
    block=sqrt(n);
    sort(q+1,q+1+m);
    moque();
    for(int i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
    return 0;
}