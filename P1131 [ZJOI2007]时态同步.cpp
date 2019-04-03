#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
struct edge
{
    int nxt,to,w;
}e[maxn<<1];
int n,s;
int head[maxn],tot;
void add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w};
}
int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);add(v,u,w);
    }
    return 0;
}