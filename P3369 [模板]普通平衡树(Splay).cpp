#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
class Splay
{
    private:
        int ch[maxn][2],f[maxn],size[maxn],v[maxn],cnt[maxn],rt,tot;
        bool chk(int x){return ch[f[x]][1]==x;}
        void pushup(int k){size[k]=size[ch[k][0]]+size[ch[k][1]]+cnt[k];}
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
        int suc(int x)
        {
            find(x);
            if(v[rt]>x) return rt;
            int cur=ch[rt][1];
            while(ch[cur][0]) cur=ch[cur][0];
            return cur;
        }
    public:
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
        void remove(int x)
        {
            int lst=pre(x),nxt=suc(x);
            splay(lst),splay(nxt,lst);
            int del=ch[nxt][0];
            if(cnt[del]>1)
            {
                cnt[del]--;
                splay(del);
            }
            else ch[nxt][0]=0,pushup(nxt),pushup(rt);
        }
        int rnk(int x){find(x);return size[ch[rt][0]];}
        int order(int x){return v[kth(x+1)];}
        int precursor(int x){return v[pre(x)];}
        int successor(int x){return v[suc(x)];}
}t;
int main()
{
    int n;
    scanf("%d", &n);
    t.insert(0x3f3f3f3f);
    t.insert(0xcfcfcfcf);
    while(n--)
    {
        int op,x;
        scanf("%d%d", &op, &x);
        switch(op)
        {
            case 1: t.insert(x); break;
            case 2: t.remove(x); break;
            case 3: printf("%d\n", t.rnk(x)); break;
            case 4: printf("%d\n", t.order(x)); break;
            case 5: printf("%d\n", t.precursor(x)); break;
            case 6: printf("%d\n", t.successor(x)); break;
        }
    }
}