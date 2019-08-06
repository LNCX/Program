#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int maxm=5e5+5;
const int inf=0x3f3f3f3f;
struct node
{
    int v;
    int w;
    int nxt;
}edg[maxm];
int n,m,s,k,num,used[maxn],dis[maxn];
int head[maxm],h[maxm],q[maxm],len=1;
void add(int from,int to,int w)
{
    edg[++num].nxt=head[from];
    edg[num].v=to;
    edg[num].w=w;
    head[from]=num;
}
void pop()
{
    int now=1,nxt;
    h[1]=h[len],q[1]=q[len],len--;
    while(2*now<=len)
    {
        nxt=now*2;
        if(nxt<len&&h[nxt+1]<h[nxt]) nxt++;
        if(h[now]<=h[nxt]) break;
        swap(h[now],h[nxt]);
        swap(q[now],q[nxt]);
        now=nxt;
    }
}
void put(int a,int b)
{
    int nxt=++len,now;
    h[len]=a,q[len]=b;
    while(1<nxt)
    {
        now=nxt>>1;
        if(h[now]<=h[nxt]) break;
        swap(h[now],h[nxt]);
        swap(q[now],q[nxt]);
        nxt=now;
    }
}
int main()
{	
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
    }
    memset(dis,inf,sizeof(dis));
    dis[s]=0,h[1]=0,q[1]=s;
    while(len)
    {
        k=q[1];pop();
        if(!used[k])
        {
            used[k]=true;
            for(int i=head[k];i!=0;i=edg[i].nxt)
            {
                int x=edg[i].w,y=edg[i].v;
                if(!used[y]&&dis[y]>dis[k]+x)
                {
                    dis[y]=dis[k]+x;
                    put(dis[y],y);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    	printf("%d ",dis[i]);
}
