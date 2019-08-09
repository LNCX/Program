#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
const int N=2e5+5;
using namespace std;
typedef long long ll;
struct point
{
    int t,x,y;
    friend bool operator <(point a,point b)
    {
        return (a.x==b.x)?a.y<b.y:a.x<b.x;
    }
}a[N],t[N];
bool cmp1(point a,point b)
{
    return a.y<b.y;
}
bool cmp2(point a,point b)
{
    return a.t<b.t;
}
int n,m,pos[N];
ll ans[N],c[N];
inline int read()
{
    int x=0;
    bool f=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-')f=0;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return f?x:-x;
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
    ll res=0;
    while(x>0)
    {
        res+=c[x];
        x-=lowbit(x);
    }
    return res;
}
void clear(int x)
{
    while(x<=n&&c[x])
    {
        c[x]=0;
        x+=lowbit(x);
    }
}
void CDQ(int l,int r)
{
    if(l==r) return;
    int mid=(l+r)>>1;
    CDQ(l,mid),CDQ(mid+1,r);
    int p=l,q=mid+1,cnt=l;
    while(p<=mid&&q<=r)
    {
        if(a[p]<a[q]) add(a[p].y,1),t[cnt++]=a[p++];
        else ans[a[q].t]+=sum(n)-sum(a[q].y),t[cnt++]=a[q++];
    }
    while(p<=mid) add(a[p].y,1),t[cnt++]=a[p++];
    while(q<=r) ans[a[q].t]+=sum(n)-sum(a[q].y),t[cnt++]=a[q++];
    for(int i=l;i<=mid;i++) 
        clear(a[i].y);
    for(int i=l;i<=r;i++) 
        a[i]=t[i];
    for(int i=r;i>=l;i--)
    {
        if(a[i].t<=mid) add(a[i].y,1);
        else ans[a[i].t]+=sum(a[i].y);
    }
    for(int i=l;i<=r;i++) 
        clear(a[i].y);
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++) 
        a[i]=(point){0,i,read()};
    int t=n;
    for(int i=1;i<=m;i++) 
        a[read()].t=t--;
    for(int i=1;i<=n;i++) 
        if(!a[i].t) 
            a[i].t=t--;
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;i++)
        a[i].y=i;
    sort(a+1,a+n+1,cmp2);  
    CDQ(1,n);
    for(int i=1;i<=n;i++) 
        ans[i]+=ans[i-1];
    for(int i=n;i>=n-m;i--) 
        printf("%lld ",ans[i]);
    return 0;
}