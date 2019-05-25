#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0;
    bool f=true;
    char c=getchar();
    while(!isdigit(c))
    {
        if(c=='-') f=false;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return f?x:-x;
}
const int maxn=1e6+5;
int cnt,n,m;
int a[maxn],t[maxn],val[maxn<<5],ch[maxn<<5][2];
int build(int l,int r)
{
    int k=++cnt,mid=(l+r)>>1;
    if(l==r)
    {
        val[k]=a[l];
        return k;
    }
    ch[k][0]=build(l,mid);
    ch[k][1]=build(mid+1,r);    
    return k;
}
int update(int pre,int l,int r,int x,int w)
{
    int k=++cnt,mid=(l+r)>>1;
    ch[k][0]=ch[pre][0],ch[k][1]=ch[pre][1],val[k]=val[pre];
    if(l==r)
    {
        val[k]=w;
        return k;
    }
    if(x<=mid) ch[k][0]=update(ch[pre][0],l,mid,x,w);
    else ch[k][1]=update(ch[pre][1],mid+1,r,x,w);
    return k;
}
int query(int k,int l,int r,int x)
{
    if(l==r) return val[k];
    int mid=(l+r)>>1;
    if(x<=mid)return query(ch[k][0],l,mid,x);
    else return query(ch[k][1],mid+1,r,x);
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    t[0]=build(1,n);
    for(int i=1;i<=m;i++)
    {
        int pre=read(),op=read(),x=read();
        if(op==1) t[i]=update(t[pre],1,n,x,read());
        if(op==2) printf("%d\n",query(t[pre],1,n,x)),t[i]=t[pre];
    }
    return 0;
}