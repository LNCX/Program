// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5;
class Splay
{
    private:
        ll sum[N],v[N];
        int ch[N][2],f[N],cnt[N],rt,tot,size[N];
        bool chk(int x){return ch[f[x]][1]==x;}
        void pushup(int k)
        {
			int l=ch[k][0],r=ch[k][1];
            size[k]=size[l]+size[r]+cnt[k];
			sum[k]=sum[l]+sum[r]+(v[k]!=(int)0x3f3f3f3f&&v[k]!=(int)0xcfcfcfcf?v[k]*cnt[k]:0);
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
		Splay()
		{
			insert(0x3f3f3f3f);
			insert(0xcfcfcfcf);
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
        ll getans()
        {
			if(size[rt]==2) return 0;
            int x=kth( (size[rt]>>1)+1 );
            insert(v[x]);
            ll res=(ll)v[x]*(size[ch[x][0]]-size[ch[x][1]])-sum[ch[x][0]]+sum[ch[x][1]];
            remove(v[x]);
            return res;        
        }
}t1,t2;
struct line
{
    int l,r;
    bool operator<(const line k) const
    {
        return l+r<k.l+k.r;
    }
    bool operator==(const line k) const
    {
        return l+r==k.l+k.r;
    }
};
ll ans,cnt;
vector<line>v;
int main()
{
    int k,n;
    scanf("%d%d",&k,&n);
    for(int i=1;i<=n;i++)
    {
        int l,r;
        char a[10],b[10];
        scanf("%s%d%s%d",a,&l,b,&r);
        if(*a==*b) cnt+=abs(l-r);
        else
        {
            cnt++;
            if(l>r) swap(l,r);
            v.push_back((line){l,r});
        }
    }
    sort(v.begin(),v.end());
    for(auto i:v)
        t2.insert(i.l),t2.insert(i.r);
    if(!v.empty())ans=t2.getans();
	if(k==1)
	{
		cout<<ans+cnt<<endl;
		return 0;
	}
    for(int i=0;i<(int)v.size();i++)
    {
		t1.insert(v[i].l),t1.insert(v[i].r);
		t2.remove(v[i].l),t2.remove(v[i].r);
        ans=min(ans,t1.getans()+t2.getans());
    }
    cout<<ans+cnt<<endl;
    return 0;
}