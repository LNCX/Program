#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<15;
class Splay
{
    private:
        int size[maxn],ch[maxn][2],cnt[maxn],f[maxn],rt;
        void pushup(int k){size[k]=size[ch[k][0]]+size[ch[k][1]]+cnt[k];}
        bool chk(int k){return ch[f[k]][1]==k;}
        void rotate(int x)
        {
            int y=f[x],z=f[y],k=chk(x);
            ch[y][k]=ch[x][k^1],f[ch[x][k^1]]=
        }
}t;
int main()
{
    return 0;
}