#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5,inf=0x3f3f3f3f;
queue<int>q[maxn],em;
int a[maxn],b[maxn];
int minx[maxn<<2],tot[maxn];
void build(int k,int l,int r)
{   
    if(l==r)
    {
        minx[k]=a[l];   
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    minx[k]=min(minx[k<<1],minx[k<<1|1]);
}
void fix(int k,int l,int r,int x)
{
   if(l>x||r<x) return;
   if(l==x&&x==r)
   {
       minx[k]=inf;
       return ;
   }
   int mid=(l+r)>>1;
   fix(k<<1,l,mid,x);
   fix(k<<1|1,mid+1,r,x);
   minx[k]=min(minx[k<<1],minx[k<<1|1]);
}
int query(int k,int l,int r,int x,int y)
{
    if(l>y||r<x) return inf;
    if(l>=x&&r<=y) return minx[k];
    int mid=(l+r)>>1;
    int res=query(k<<1,l,mid,x,y);
    res=min(res,query(k<<1|1,mid+1,r,x,y));
    return res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            tot[i]=0,q[i]=em;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            tot[a[i]]++,q[a[i]].push(i);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            tot[b[i]]--;
        }
        bool flag=true; 
        for(int i=1;i<=n;i++)
            if(tot[i])
            {
                puts("NO");
                flag=false;
                break;
            }
        if(!flag) continue;
        build(1,1,n);
        for(int i=1;i<=n;i++)
        {
            int p=q[b[i]].front();q[b[i]].pop();
            if(query(1,1,n,1,p)!=b[i])
            {
                flag=false;
                break;
            }
            else fix(1,1,n,p);
        }
        flag?puts("YES"):puts("NO");
    }
}
