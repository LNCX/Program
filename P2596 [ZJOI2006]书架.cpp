#include<bits/stdc++.h>
using namespace std;
const int N=8e5+5;
int f[N],size[N],ch[N][2],rt,pos[N],rev[N];
void pushup(int k){size[k]=size[ch[k][0]]+size[ch[k][1]]+1;}
bool chk(int x){return ch[f[x]][1]==x;}
void rotate(int x)
{
    int y=f[x],z=f[y],k=chk(x);
    ch[y][k]=ch[x][k^1],f[ch[x][k^1]]=y;
    ch[z][chk(y)]=x,f[x]=z;
    ch[x][k^1]=y,f[y]=x;
    pushup(y),pushup(x);
}
void splay(int x,int k=0)
{
    while(f[x]!=k)
    {
        int y=f[x],z=f[y];
        if(z!=k)
        {
            if(chk(x)==chk(y)) rotate(y);
            else rotate(x);
        }
        rotate(x);
    }
    if(!k) rt=x;
}
void build(int l,int r,int fa)
{
    if(l>r) return ;
    int mid=(l+r)>>1;
    if(mid<fa) ch[fa][0]=mid;
    else ch[fa][1]=mid;
    f[mid]=fa,size[mid]=1;
    if(l==r) return;
    build(l,mid-1,mid),build(mid+1,r,mid);
    pushup(mid);
}
int find(int k)
{
    int cur=rt;
    while(1)
    {
        if(ch[cur][0]&&k<=size[ch[cur][0]])
            cur=ch[cur][0];
        else if(k>size[ch[cur][0]]+1)
        {
            k-=size[ch[cur][0]]+1;
            cur=ch[cur][1];
        }
        else return cur;
    }
}
void top(int k)
{
    splay(k);
    if(!ch[rt][0]) return ;
    else if(!ch[rt][1]) ch[rt][1]=ch[rt][0],ch[rt][0]=0;
    else
    {
        int y=find(size[ch[rt][0]]+2);
        ch[y][0]=ch[rt][0],f[ch[rt][0]]=y;
        ch[rt][0]=0;
        splay(y);
    }
}
void bottom(int k)
{
    splay(k);
    if(!ch[rt][1]) return;
    else if(!ch[rt][0]) ch[rt][0]=ch[rt][1],ch[rt][1]=0;
    else
    {
        int y=find(size[ch[rt][0]]);
        ch[y][1]=ch[rt][1],f[ch[rt][1]]=y;
        ch[rt][1]=0;
        splay(y);
    }
}
void change(int x,int p)
{
    splay(x);
    int y;
    if(p==0) return ;
    if(p==-1) y=find(size[ch[x][0]]);
    else y=find(size[ch[rt][0]]+2);
    swap(rev[x],rev[y]);
    swap(pos[rev[x]],pos[rev[y]]);  
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        pos[x]=i,rev[i]=x;
    }
    rt=(1+n)>>1;
    build(1,n,0);
    while(m--)
    {
        int x,y;
        char s[10];
        scanf("%s%d",s,&x);
        switch(*s)
        {
            case 'T':
                top(pos[x]);
                break;
            case 'B':
                bottom(pos[x]);
                break;
            case 'I':
                scanf("%d",&y);
                change(pos[x],y);
                break;
            case 'A':
                splay(pos[x]);
                printf("%d\n",size[ch[rt][0]]);
                break;
            case 'Q':
                int y=find(x);
                printf("%d\n",rev[y]);
                break;
        }
    }
}