#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||'9'<c)
        c=getchar();
    while('0'<=c&&c<='9')
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
const int maxn=1e5+5,maxm=2e5+5;
struct Edge
{
    int to,cap,nxt,flow,from;
}e[maxm];
int tot,head[maxn];
void Add(int from,int to,int cap)
{
    e[++tot].nxt=head[from];
    e[tot].cap=cap;
    e[tot].to=to;
    head[from]=tot;
}
queue<int>q;
int bfs(int s,int t)
{
    q.push(s);

}
void EK(int s,int t)
{
    int add=0;
    while(add=bfs(s,t)!=-1)
    {

    }
}
int main()
{
    int n=read(),m=read(),s=read(),t=read();
    for(int i=1;i<=m;i++)
        Add(read(),read(),read());
    EK(s,t);
    return 0;
}