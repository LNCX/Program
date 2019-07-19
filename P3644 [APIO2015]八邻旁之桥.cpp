#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int ans,add;
const int maxn=1e5+5;
class Splay
{
    private:
        int size[maxn],sum[maxn],cnt[maxn],ch[maxn][2],f[maxn],v[maxn],rt;
        bool chk(int k){return ch[f[k]][1]==k;}
        void pushup(int k)
        {
            sum[k]=sum[ch[k][0]]+sum[ch[k][1]]+v[k]*cnt[k];
            size[k]=size[ch[k][0]]+size[ch[k][1]]+cnt[k];
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
                int y=f[x],z=f[y];
                if(z!=k)
                {
                    if(chk(y)==chk(x)) rotate(y);
                    else rotate(y);
                }
                rotate(x);
            }
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
               f[cur]=fa;
               sum[cur]=v[cur]=x;
               cnt[cur]=size[cur]=1;
               ch[cur][0]=ch[cur][1]=0;
            }
            splay(cur);
        }
}t;
int main()
{
    ios::sync_with_stdio(0);
    int k,n;
    cin>>k>>n;
    for(int i=1;i<=n;i++)
    {
        char a,b;
        int x,y;
        cin>>a>>x>>b>>y;
        if(a==b) add+=(x+y);
        else v.push_back(x+y),add++;
    }
    sort(v.begin(),v.end());
    if(k==1)
    {
        int ans=0;
        
    }
    return 0;
}