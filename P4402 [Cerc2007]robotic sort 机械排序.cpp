#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5,oo=0x3f3f3f3f;
int rt,ch[maxn][2],size[maxn],fa[maxn],rev[maxn];
struct node
{
    int id,v;
    bool operator<(const node &x) const
    {
        if(v!=x.v) return v<x.v;
        return id<x.id;
    }
}a[maxn];
void pushup(int x){size[x]=size[ch[x][0]]+size[ch[x][1]]+1;}
void pushdown(int x)
{
    if(rev[x])
    {
        if(ch[x][0]) rev[ch[x][0]]^=1;
        if(ch[x][1]) rev[ch[x][1]]^=1;
        swap(ch[x][0],ch[x][1]);
        rev[x]=0;
    }
}
void build(int l,int r,int f)
{
    if(l>r) return ;
    int mid=(l+r)>>1;
    fa[mid]=f;size[mid]=1;  
    if(mid<f) ch[f][0]=mid;
    else ch[f][1]=mid;
    if(l==r) return ;
    build(l,mid-1,mid);
    build(mid+1,r,mid);
    pushup(mid);
}
void rotate(int x)
{
    int y=fa[x],z=fa[y],k=(ch[fa[x]][1]==x);
    pushdown(y),pushdown(x);
    ch[y][k]=ch[x][k^1],fa[ch[y][k]]=y;
    ch[x][k^1]=y,fa[y]=x,fa[x]=z;
    if(z) ch[z][ch[z][1]==y]=x;
    pushup(y);pushup(x);
}
int find(int x)
{
    int now=rt;
    while(1)
    {
        if(rev[now])
        pushdown(now);
        if(x<=size[ch[now][0]]&&ch[now][0])
            now=ch[now][0];
        else 
        {
            x-=size[ch[now][0]]+1;
            if(x==0) return now;
            else now=ch[now][1];
        }
    }
}
void splay(int x,int k=0)
{
    while(fa[x]!=k)
    {
        int y=fa[x],z=fa[y];
        pushdown(z),pushdown(y),pushdown(x);
        if(z!=k)
        {
            if((ch[y][0]==x)^(ch[z][0]==y)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if(!k) rt=x;
}
int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n+1;i++)
        scanf("%d",&a[i].v),a[i].id=i;
    a[1].v=-oo,a[n+2].v=oo;
    a[1].id=1,a[n+2].id=n+2;
    sort(a+1,a+3+n);
    build(1,n+2,0);
    rt=(n+3)>>1;
    for(int i=2;i<=n;i++)
    {
        splay(a[i].id,0);
        int ans=size[ch[rt][0]]+1;
        printf("%d ",ans-1);
        int x=find(i-1);
        int y=find(ans+1);
        splay(x,0);splay(y,x);
        rev[ch[ch[rt][1]][0]]^=1;
    }
    printf("%d\n",n);
    return 0;
}