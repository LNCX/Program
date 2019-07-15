#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<20,inf=0x3f3f3f3f;
class Splay
{
    private:
        int cnt[maxn],ch[maxn][2],f[maxn],v[maxn],rt,tot;
        bool chk(int k){return ch[f[k]][1]==k;}
        void rotate(int x)
        {
            int y=f[x],z=f[y],k=chk(x);
            ch[y][k]=ch[x][k^1],f[ch[x][k^1]]=y;
            ch[z][chk(y)]=x,f[x]=z;
            ch[x][k^1]=y,f[y]=x;
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
            while(ch[cur][x>v[cur]]&&v[cur]!=x)
                cur=ch[cur][x>v[cur]];
            splay(cur);
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
                //cerr<<tot<<endl;
                cur=++tot;
                if(fa) ch[fa][x>v[fa]]=cur;
                cnt[cur]=1;
                ch[cur][0]=ch[cur][1]=0;
                f[cur]=fa,v[cur]=x;
            }
            splay(cur);
        }
        int pre(int x)
        {
            find(x);
            if(v[rt]<x) return v[rt];
            if(cnt[rt]>1) return v[rt];
            int cur=ch[rt][0];
            while(ch[cur][1])
                cur=ch[cur][1];
            splay(cur);
            return v[cur]; 
        }
        int succ(int x)
        {
            find(x);
            if(v[rt]>x) return v[rt];
            if(cnt[rt]>1) return v[rt];
            int cur=ch[rt][1];
            while(ch[cur][0])
                cur=ch[cur][0];
            splay(cur);
            return v[cur];
        }
}t;
int main()
{
    int n,ans=0;
    cin>>n;
    t.insert(inf),t.insert(-inf);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        t.insert(x);
        if(i==1) ans+=x;
        else
        {
            int tmp=0x3f3f3f3f;
            int a=t.pre(x),b=t.succ(x);
            //cerr<<a<<" "<<x<<" "<<b<<endl;
            if(a!=-inf) tmp=min(abs(x-a),tmp);
            if(b!=inf) tmp=min(abs(x-b),tmp);
            ans+=tmp; 
        }
    }
    cout<<ans<<endl;
    return 0;
}