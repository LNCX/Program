#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5,maxm=1e5+5;
struct Edge
{
    int from,to,cap,nxt,w,flow;
}e[maxm];
int head[maxn],tot=1;
void Add(int from,int to,int cap,int w)
{
    e[++tot].nxt=head[from];
    
}
int main()
{
    int n,m,s,t;
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;i++)
    {
        int u,v,w,f;
        scanf("%d%d%d%d",&u,&v,&w,&f);
        Add(u,v,w,f);Add(v,u,0,-f);
    }
    return 0;
}