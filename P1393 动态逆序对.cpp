#include<bits/stdc++.h>
using namespace std;
const int maxn=4e4+5;
struct point 
{
    int x,y,z;
    bool operator<(const point &a) const
    {
        if(x!=a.x) return x<a.x;
        if(y!=a.y) return y<a.y;
        return z<a.z;
    } 
}a[maxn],t[maxn];
int read()
{
    int x=0,f=1;
    char c=getchar();
    while(!isdigit(c)) {if(c=='-') f=-1;c=getchar();}
    while(isdigit(c)) {x=(x<<3+x<<1+c-'0');c=getchar();}
    return f==1?x:-x;
}
void CDQ(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)>>1;
    CDQ(l,mid),CDQ(mid+1,r);
    
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        a[i].x=i;
        a[i].y=read();
    }
    for(int i=1;i<=m;i++)
        a[read()].z=i;
    sort(a+1,a+1+n);
    CDQ(1,n);
    return 0;
}