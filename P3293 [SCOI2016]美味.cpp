#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],rt,t[N<<5],ch[N<<5][2],sum[N<<5];
void update(int pre,int &k,int l,int r,int x)
{ 
    if(r<x||l>x) return ;
    k=++rt,ch[k][0]=ch[pre][0],ch[k][1]=ch[pre][1],sum[k]=sum[pre]+1;
    if(l==r) return;
    int mid=(l+r)>>1;
    update(ch[pre][0],ch[k][0],l,mid,x);
    update(ch[pre][1],ch[k][1],mid+1,r,x);
}
int query(int u,int v,int l,int r,int x,int y)
{
    int num=sum[v]-sum[u],mid=(l+r)>>1;
    if(y<l||x>r||num==0) return 0;
    if(x<=l&&r<=y) return num;
    return query(ch[u][0],ch[v][0],l,mid,x,y)+query(ch[u][1],ch[v][1],mid+1,r,x,y);
}
int main()
{
    int n,m,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),m=max(a[i],m);
    for(int i=1;i<=n;i++)
        update(t[i-1],t[i],0,m,a[i]);
    while(q--)
    {
        int b,x,l,r,ans=0;
        scanf("%d%d%d%d",&b,&x,&l,&r);
        for(int i=18;i>=0;i--)
        {
            if(b&(1<<i)&&!query(t[l-1],t[r],0,m,ans-x,ans-x+(1<<i)-1)) ans+=(1<<i);
            if(!(b&(1<<i))&&query(t[l-1],t[r],0,m,ans-x+(1<<i),ans-x+(1<<(i+1))-1)) ans+=(1<<i);
        }      
        printf("%d\n",ans^b);
    }
    return 0;
}