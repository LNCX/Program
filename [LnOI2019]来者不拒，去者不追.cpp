#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&(-x))
typedef long long ll;
const int N=100;
ll p[N],c[N],now,ans[N];
int n,m,a[N],blg[N],block;
void read(){}
template<typename T,typename... Ts>
inline void read(T &arg,Ts&... args)
{
    T x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c-'0');c=getchar();}
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
void update(int x,int y)
{
    int u=x;  
    while(u<=n)
    {
        p[u]+=y,c[u]+=(ll)u*y;
        u+=lowbit(u);
    }
}
int num(int x)
{
    int res=0;
    while(x>0)
    {   
        res+=p[x];
        x-=lowbit(x);
    }           
    return res;
}
ll ask(int x)
{
    ll res=0;
    while(x>0)
    {   
        res+=c[x];
        x-=lowbit(x);
    }           
    return res;
}
void add(int x)
{
    x=a[x];
    now+=(ll)(num(x-1)+1)*x;
    now+=ask(n)-ask(x);
    update(x,1);
}
void del(int x)
{
    x=a[x];
    now-=(ll)(num(x-1)+1)*x;
    now-=ask(n)-ask(x);
    update(x,-1);
}
void moque()
{
    int l=1,r=0;
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
int main()
{   
    read(n,m);
    for(int i=1;i<=n;i++)
        read(a[i]);
    for(int i=1;i<=m;i++)
    {
        int l,r;
        read(l,r);
        cerr<<l<<" "<<r<<endl;
        q[i]=(node){l,r,i};
    }
    block=sqrt(n);
    sort(q+1,q+1+n);
    moque();
    for(int i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
    return 0;
}