#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
inline int read()
{
    int x=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();   
    while(isdigit(c))
    {
        x=x*10+c-'0';

    }
}
struct edge
{
    int nxt,to,w;
}e[maxn<<1];
int head[maxn],tot;
void add(int u,int v,int w)
{
    e[++tot]=(edge){head[u],v,w};
    head[u]=tot;
}
void dfs(int u,int fa)
{
    
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        scanf("%D%D%D",&u,&v,&w);
        add(u,v,w),add(v,u,w);
    }
    while(m--)
    {
        int k;
        scanf("%d",&k);
        bool ans=true;
    }
    return 0;
}