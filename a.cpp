#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct LCT
{
    private:
        int r[N],f[N],v[N],size[N],ch[N][2],rt;
        bool chk(int x){return ch[f[x]][1]==x;}
        void pushup(int x){size[x]=size[ch[x][0]]+size[ch[x][1]];}
        void psuhdown(int x)
        {

        }
        void rotate(int x)
        {
            int y=f[x],z=f[y],k=chk(x);
            ch[y][k]=ch[x][k^1],f[ch[x][k^1]]=y;
            ch[k][chk(y)]=x,f[x]=z;
            ch[x][k^1]=y,f[y]=x;
        }
        void splay(int x,int k=0)
        {

        }
        void access(int x)
        {
            for(int y=0;x;y=x,x=f[x])
            {
                splay(x);
                ch[x][1]=y;
                pushup(x);
            }
        }
        int findrt(int x)
        {

        }
        void makert(int x)
        {

        }
    public:
        
};   
int main()
{
    
    return 0;
}
