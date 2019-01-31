#include <bits/stdc++.h>
using namespace std;
const int maxn=1000001;
struct nodea{ int x,y,g; } b[maxn];
struct nodeb{ int h; } r[maxn];
int ans[maxn],f[maxn],c[maxn],x[maxn];
int len=0,cnt=0,p=0;
int n=0,m=0;
void ins(int x,int y)
{
    len++;
    b[len].x=x;
    b[len].y=y;
    b[len].g=r[x].h;
    r[x].h=len;
}
int find(int x)
{
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
void add(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
        f[fx]=fy;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y++;
        ins(x,y),ins(y,x);
    }
    int q=0;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d",&x[i]);
        x[i]++;
        c[x[i]]=1;
    }
    for(int k=1;k<=n;k++) if(c[k]==0)
        for(int i=r[k].h;i>0;i=b[i].g) if(c[b[i].x]==0 && c[b[i].y]==0)
            add(b[i].x,b[i].y);
    for(int i=1;i<=n;i++)
        if(c[i]==0 && f[i]==i)
            cnt++;
    ans[++p]=cnt;
    for(int j=q;j>=1;j--)
    {
        cnt++;
        c[x[j]]=0;
        for(int i=r[x[j]].h;i>0;i=b[i].g)
            if(c[b[i].x]==0 && c[b[i].y]==0 && find(b[i].x)!=find(b[i].y))
                cnt--,add(b[i].x,b[i].y);
        ans[++p]=cnt;
    }
    for(int i=p;i>=1;i--)
        printf("%d\n",ans[i]);
    return 0;
}