#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
struct LCT
{
    private:
        int s[N],f[N],v[N],ch[N][2],r[N],rt;
        bool chk(int x){return ch[f[x]][1]==x;}
        bool get(int x){return ch[f[x]][0]==x||ch[f[x]][1]==x;}
        void pushup(int x){s[x]=s[ch[x][0]]^s[ch[x][1]]^a[x];}
        void pushdown(int x)
        {
            if(!r[x]) return;
            swap(ch[x][1],ch[x][0]);
            r[ch[x][1]]^=1,r[ch[x][0]]^=1;
            r[x]=0;
        }
        void pushadd(int x)
        {
            while(get(x)) pushadd(f[x]);
            pushdown(x);
        }
        void rotate(int x)
        {
            int y=f[x],z=f[y],k=chk(x);
            ch[y][k]=ch[x][k^1],f[ch[x][k^1]]=y;
            ch[k][chk(y)]=x,f[x]=z;
            ch[x][k^1]=y,f[y]=x;
        }
        void splay(int x)
        {
            pushadd(x);
            while(get(x))
            {
                int y=f[x],z=f[y];
                if(get(y)) chk(x)==chk(y)?rotate(y):rotate(x);
                rotate(x);
            }
        }
        void access(int x)
        {
            for(int y=0;x;y=x,x=f[x])
                splay(x),ch[x][1]=y,pushup(x);
        }
    public:
        int findrt(int x)
        {
            access(x),splay(x);
            while(ch[x][0]) x=ch[x][0];
            return x;
        }
        void makert(int x)
        {
            access(x),splay(x);
            r[x]^=1,pushdown(x);
        }
        void split(int x,int y)
        {
            makert(x)
        }
};   
int main()
{
    
    return 0;
}
