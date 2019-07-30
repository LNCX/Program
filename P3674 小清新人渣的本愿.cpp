#include<bits/stdc++.h>
using namespace std;
const int N=1e5,M=N+5;
int m,n,t,a[M],c[M],ans[M],blg[M];
bitset<M>s1,s2;
struct node
{
    int o,l,r,x,id;
    friend bool operator<(node x,node y)
    {
        return blg[x.l]==blg[y.l]?blg[x.l]&1?x.r<y.r:x.r>y.r:blg[x.l]<blg[y.l];
    }
}q[M];
void add(int x)
{
    if(c[x]++==0)
        s1[x]=1,s2[N-x]=1;
}
void del(int x)
{
    if(--c[x]==0)
        s1[x]=0,s2[N-x]=0;
}
int main()
{
    scanf("%d%d",&n,&m);
    t=sqrt(n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        blg[i]=(i-1)/t+1;
    }
    for(int i=1;i<=m;i++)
    {
        q[i].id=i;
        scanf("%d%d%d%d",&q[i].o,&q[i].l,&q[i].r,&q[i].x);
    }
    sort(q+1,q+1+m);
    int l=1,r=0;
    for(int i=1;i<=m;i++)
    {
        while(l<q[i].l) del(a[l++]);
        while(l>q[i].l) add(a[--l]);
        while(r>q[i].r) del(a[r--]);
        while(r<q[i].r) add(a[++r]);
        int o=q[i].o,x=q[i].x,id=q[i].id;
        if(o==1&&(s1&(s1<<x)).any()) ans[id]=1;
        if(o==2&&(s1&(s2>>(N-x))).any()) ans[id]=1;
        if(o==3)
        {
            for(int j=1;j*j<=x;j++)
                if(x%j==0&&s1[j]&&s1[x/j])
                {
                    ans[id]=1;
                    break;
                }
        }
    }
    for(int i=1;i<=m;i++)
        puts(ans[i]?"hana":"bi");
    return 0;
}