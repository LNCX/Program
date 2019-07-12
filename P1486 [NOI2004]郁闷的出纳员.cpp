#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int rt,tot,ch[maxn][2],f[maxn],cnt[maxn],v[maxn],size[maxn];
bool chk(int x){return ch[f[x]][1]==x;}
void pushup(int x){size[x]=size[ch[x][0]]+size[ch[x][1]]+cnt[x];}
void rotate(int x)
{
    int y=f[x],z=f[y],k=chk(x);
    ch[y][k]=ch[x][k^1],f[ch[x][k^1]]=y;
    ch[z][chk(y)]=x,f[x]=z;
    ch[x][k^1]=y,f[y]=x;
    pushup(x),pushup(y);
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
void insert(int x)
{
    int cur=rt,fa=0;
    while(cur&&v[cur]!=x)
    {
        fa=cur;
        cur=ch[cur][x>v[cur]];
    }
    if(cur) cnt[cur]++;
    else
    {
        cur=++tot;
        if(fa) ch[fa][x>v[fa]]=cur;
        ch[cur][0]=ch[cur][1]=0;
        f[cur]=fa,v[cur]=x;
        cnt[cur]=size[cur]=1;
    }
    splay(cur);
}
void find(int x)
{
    int cur=rt;
    while(ch[cur][x>v[cur]]&&x!=v[cur])
        cur=ch[cur][x>v[cur]];
    splay(cur);
}
int kth(int k)
{
    int cur=rt;
    while(1)
    {
        if(ch[cur][0]&&k<=size[ch[cur][0]])
            cur=ch[cur][0];
        else if(k>size[ch[cur][0]]+cnt[cur])
        {
            k-=size[ch[cur][0]]+cnt[cur];
            cur=ch[cur][1];
        }
        else return cur;
    }
}
int pre(int x)
{
    find(x);
    if(v[rt]<x) return rt;
    int cur=ch[rt][0];
    while(ch[cur][1]) cur=ch[cur][1];
    return cur;
}
int succ(int x)
{
    find(x);
    if(v[rt]>x) return rt;
    int cur=ch[rt][1];
    while(ch[cur][0]) cur=ch[cur][0];
    return cur;
}
void remove(int x)
{
    int last=pre(x),next=succ(x);
    splay(last),splay(next,last);
    int del=ch[next][0];
    if(cnt[del]>1)
    {
        cnt[del]--;
        splay(del);
    }
    else ch[next][0]=0,pushup(next),pushup(rt);
}
int main()
{
    int n,minx,sum=0;
    scanf("%d%d", &n,&minx);
    while(n--)
    {
        int k;
        char s[10];
        scanf("%s%d",s,k);
        switch(s[0])
        {
            case 'I':insert(k-sum);break;
            case 'A':sum+=k,minx-=k;break;
            case 'S':sum-=k,minx+=k;break;
            case 'F':
            {
                insert(minx);
                succ()
            }
        }
    }
}