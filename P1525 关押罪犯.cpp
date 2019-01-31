#include<bits/stdc++.h>
using namespace std;
const int maxm=2e5+5;
struct node
{
    int u,v,w;
    bool operator <(const node &x) const
    {return this->w>x.w;}
}a[maxm];
int b[maxm],f[maxm];
int find(int x)
{
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
void ad(int x,int y)
{
    x=find(x);y=find(y);
    f[x]=y;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
    sort(a+1,a+1+m);
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
    {
        if(find(a[i].u)==find(a[i].v)){printf("%d\n",a[i].w);return 0;}
        if(!b[a[i].u]) b[a[i].u]=a[i].v;
            else ad(b[a[i].u],a[i].v);
        if(!b[a[i].v]) b[a[i].v]=a[i].u;
            else ad(b[a[i].v],a[i].u);
    }
    cout<<0<<endl;
    return 0;
}