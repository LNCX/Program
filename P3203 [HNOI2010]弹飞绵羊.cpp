// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int k[N],f[N],ch[N][2],r[N],size[N];
bool chk(int x){return ch[f[x]][1]==x;}
bool get(int x){return ch[f[x]][1]==x||ch[f[x]][0]==x;}
void flip(int x){swap(ch[x][0],ch[x][1]);r[x]^=1;}
void pushup(int x){size[x]=size[ch[x][0]]+size[ch[x][1]]+1;}
void pushdown(int x)
{
    if(!r[x]) return;
    if(ch[x][0]) flip(ch[x][0]);
    if(ch[x][1]) flip(ch[x][1]);
    r[x]=0;
}
void pushadd(int x)
{
    if(get(x)) pushadd(f[x]);
    pushdown(x);
}
void rotate(int x)
{
    int y=f[x],z=f[y],k=chk(x);
    ch[y][k]=ch[x][k^1],f[ch[x][k^1]]=y;
    if(get(y)) ch[z][chk(y)]=x;f[x]=z;
    ch[x][k^1]=y,f[y]=x;
    pushup(y),pushup(x);
}
void splay(int x)
{
    pushadd(x);
    while(get(x))
    {
        int y=f[x];
        if(get(y)) chk(x)==chk(y)?rotate(y):rotate(x);
        rotate(x);
    }
}
void access(int x)
{
    for(int y=0;x;y=x,x=f[x])
        splay(x),ch[x][1]=y,pushup(x);
}
void makert(int x)
{
    access(x),splay(x),flip(x);
}
int findrt(int x)
{
    access(x),splay(x);
    while(ch[x][0]) pushdown(x),x=ch[x][0];
    return x;
}
void split(int x,int y)
{
    makert(x),access(y),splay(y);
}
void link(int x,int y)
{
    makert(x);
    if(findrt(y)!=x) f[x]=y;
}
void cut(int x,int y)
{
    split(x,y);
    if(findrt(y)==x&&f[x]==y&&!ch[x][1])
        f[x]=ch[y][0]=0,pushup(y);
}
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&k[i]);
    for(int i=1;i<=n;i++)
        link(i,i+k[i]<=n?i+k[i]:n+1);
    scanf("%d",&m);
    while(m--)
    {
        int op,x,y;
        scanf("%d%d",&op,&x);x++;
        if(op==1)
        {
            makert(x);
            access(n+1);
            splay(n+1);
            printf("%d\n",size[n+1]-1);
        }
        else
        {
            scanf("%d",&y);
            cut(x,x+k[x]<=n?x+k[x]:n+1);
            link(x,x+y<=n?x+y:n+1);
            k[x]=y;
        }
    }
    return 0;
}