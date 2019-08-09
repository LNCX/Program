#include <bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int N=200000+10;
const int inf=1e9;
int n,m,c[N],ans[N],cnt;
struct Query
{
    int l,r,k,op,id;
}q[N<<1],q1[N<<1],q2[N<<1];
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return (f==1)?x:-x;
}
void add(int x,int y)
{
    while(x<=n)
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
void solve(int l,int r,int L,int R)
{
    if(L>R) return ;
    if(l==r)
    {
        for(int i=L;i<=R;i++) 
            if(q[i].op==2) ans[q[i].id]=l;
        return ; 
    }
    int mid=(l+r)>>1,cnt1=0,cnt2=0,x;
    for(int i=L;i<=R;i++)
    {
        if(q[i].op==1)
        {
            if(q[i].l<=mid) q1[++cnt1]=q[i],add(q[i].id,q[i].r);
            else q2[++cnt2]=q[i];
        }
        else 
        {
            x=sum(q[i].r)-sum(q[i].l-1);
            if(q[i].k<=x) q1[++cnt1]=q[i];
            else q[i].k-=x,q2[++cnt2]=q[i];
        }
    }
    for(int i=1;i<=cnt1;i++)
        if(q1[i].op==1) 
            add(q1[i].id,-q1[i].r);
    for(int i=1;i<=cnt1;i++) 
        q[L+i-1]=q1[i];
    for(int i=1;i<=cnt2;i++) 
        q[L+i+cnt1-1]=q2[i];
    solve(l,mid,L,L+cnt1-1);
    solve(mid+1,r,L+cnt1,R);
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        q[++cnt]=(Query){read(),1,0,1,i};
    for(int i=1;i<=m;i++)
        q[++cnt]=(Query){read(),read(),read(),2,i};
    solve(-inf,inf,1,cnt);
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}