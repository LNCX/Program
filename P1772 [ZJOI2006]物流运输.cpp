#include<bits/stdc++.h>
using namespace std;
const int maxm=25;
const int maxe=1e3+5;
inline int read()
{
    int x=0;
    char c=getchar();
    while('0'>c||'9'<c) c=getchar();
    while('0'<=c&&c<='9')
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
int n,m,k,e;
int head[maxm],w[maxe],to[maxe],nxt[maxe],edge_sum;
void add(int x,int y,int z)
{
    nxt[++edge_sum]=head[x];
    head[x]=edge_sum;
    to[edge_sum]=y;
    w[edge_sum]=z;
}
int main(int argc, char const *argv[])
{
    n=read(),m=read(),k=read(),e=read();
    for(int i=1;i<=e;i++)
    {
        int x=read(),y=read(),z=read();
        add(x,y,z),add(y,x,z);
    }
    
    return 0;
}