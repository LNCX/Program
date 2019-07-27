#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
priority_queue<int>q;
class Splay
{
    private:
        int cnt[N],size[N],tag[N],ch[N][0],f[N],v[N],rt;
        bool chk(int x){return ch[f[x]][1]==x;}
        void pushup(int x){size[x]=size[ch[x][0]]+size[ch[x][1]]+cnt[x];}
        void pushdown(int x)
        {
            if(!tag[x]) return;
            v[ch[x][0]]+=tag[x];
            v[ch[x][1]]+=tag[x];
            tag[x]=0;
        }
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
                int y=f[x];
                if(f[y]!=k) chk(x)==chk(y)?rotate(y):rotate(x);
                rotate(x);
            }
            if(!k) rt=x;
        }
    public:
        void insert(int x)
        {
            int cur=rt,fa=0;
            while(cur&&v[cur]!=x)
            {
                cur=ch[cur][x>cv[cur]];
            }
        }
};
int w[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    
    return 0;
}