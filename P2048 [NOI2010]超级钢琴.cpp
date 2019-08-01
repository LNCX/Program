#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,k,L,R,cnt;
ll sum[N],ans,a[N];
class RMQ
{
    private:
        int f[N][19],log[N]={-1};
    public:
        void init()
        {
            for(int i=1;i<=n;i++)
            {
                f[i][0]=i;
                log[i]=log[i>>1]+1;
            }
            for(int j=1;(1<<j)<=n;j++)
                for(int i=1;i+(1<<j)-1<=n;i++)
                {
                    int x=f[i][j-1],y=f[i+(1<<(j-1))][j-1];
                    f[i][j]=sum[x]>sum[y]?x:y;
                }
        }
        int find(int l,int r)
        {
            int k=log[r-l+1];
            int x=f[l][k],y=f[r-(1<<k)+1][k];
            return sum[x]>sum[y]?x:y;
        }
}st;
struct node
{
    int o,l,r,t;
    node(int o,int l,int r):o(o),l(l),r(r),t(st.find(l,r)){}
    bool operator<(const node&k)const
    {
        return sum[t]-sum[o-1]<sum[k.t]-sum[k.o-1];
    }
};
priority_queue<node>q;
int main()
{
    scanf("%d%d%d%d",&n,&k,&L,&R);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]),sum[i]=sum[i-1]+a[i];
    st.init();
    for(int i=1;i+L-1<=n;i++)
    {
        node x=node(i,i+L-1,min(i+R-1,n));
        q.push(x);
    }
    while(!q.empty())
    {
        int o=q.top().o,l=q.top().l,r=q.top().r,t=q.top().t;
        q.pop(),ans+=sum[t]-sum[o-1],cnt++;
        if(cnt==k) break;
        if(t!=l) q.push(node(o,l,t-1));
        if(t!=r) q.push(node(o,t+1,r));
    }
    cout<<ans<<endl;
    return 0;
}