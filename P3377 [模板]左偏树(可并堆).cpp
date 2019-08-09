#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int ch[N][2],val[N],f[N],dist[N];
int n,m;
bool vis[N];
int find(int x){return x==f[x]?f[x]:f[x]=find(f[x]);}
int merge(int x,int y)
{
    if(!x||!y) return x|y;
    if(val[x]>val[y]) 
        swap(x,y);
    ch[x][1]=merge(ch[x][1],y);
    if(dist[ch[x][0]]<dist[ch[x][1]]) 
        swap(ch[x][0],ch[x][1]);
    dist[x]=dist[ch[x][1]]+1;
    f[ch[x][0]]=f[ch[x][1]]=x;
    return x;
}
int pop(int x)
{
    if(vis[x]) return -1;
    vis[x]=1;
    int res=val[x];
    f[ch[x][0]]=ch[x][0];
    f[ch[x][1]]=ch[x][1];
    f[x]=merge(ch[x][0],ch[x][1]);
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&val[i]),f[i]=i;
    while(m--)
    {
        int opt,x,y;
        scanf("%d",&opt);
        if(opt==1)
        {
            scanf("%d%d",&x,&y);
            if((!vis[x])&&(!vis[y]))
                merge(find(x),find(y));
        }
        else
        {
            scanf("%d",&x);
            if(vis[x]) printf("-1\n");
            else printf("%d\n",pop(find(x)));
        }
    }
    return 0;
}