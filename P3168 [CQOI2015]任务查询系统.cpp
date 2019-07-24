#include<bits/stdc++.h>
const int N=1e5+5;
using namespace std;
int n,q,m,tot;
struct point
{
    int l,r,size;
    long long sum;
}P[5000010];
struct xx
{
    int key,s,w;
}L[2*N];
int A[N];
int Li[N];
int root[N];
int cmp(const xx &a,const xx &b)
{
    return a.key<b.key || a.key==b.key && a.s>b.s;
}
void Change(int y,int &x,int l,int r,int p,int w,int t)
{
    P[x=++tot]=P[y];
    P[x].size+=w;
    P[x].sum+=t*w;
    if(l==r) return;
    int mid=(l+r)/2;
    if(p<=mid) Change(P[y].l,P[x].l,l,mid,p,w,t);
    else Change(P[y].r,P[x].r,mid+1,r,p,w,t);
}
long long find(int x,int l,int r,int w)
{
    if(w<=0) return 0;
    if(P[x].size<=w)
        return P[x].sum;
    if(l==r)
        return (long long)w*Li[l];
    int mid=(l+r)/2;
    long long s=0;
    s+=find(P[x].l,l,mid,w);
    s+=find(P[x].r,mid+1,r,w-P[P[x].l].size);
    return s;
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&L[i*2-1].key,&L[i*2].key);
        ++L[i*2].key;
        L[i*2-1].s=1; L[i*2].s=-1;
        L[i*2-1].w=L[i*2].w=i;
        scanf("%d",&A[i]);
        Li[++m]=A[i];
    }
    sort(Li+1,Li+m+1);
    m=unique(Li+1,Li+m+1)-Li-1;
    for(int i=1;i<=n;++i)
        A[i]=lower_bound(Li+1,Li+m+1,A[i])-Li;
    sort(L+1,L+2*n+1,cmp);
    for(int k=1;k<=2*n;++k)
    {
        for(int i=L[k-1].key+1;i<L[k].key&&i^1;++i)
            root[i]=root[i-1];
        Change(root[L[k-1].key],root[L[k].key],1,m,A[L[k].w],L[k].s,Li[A[L[k].w]]);
    }
    for(int i=L[2*n].key+1;i<=q+1;++i)
        root[i]=root[i-1];
    long long ans=1;
    while(q--)
    {
        int x,A,B,C;
        scanf("%d%d%d%d",&x,&A,&B,&C);
        int k=1+(ans*A+B)%C;
        ans=find(root[x],1,m,k);
        printf("%lld\n",ans);
    }
}

