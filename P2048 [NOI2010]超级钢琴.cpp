#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,L,R,a[N],sum[N];
class RMQ
{
    private:
        int f[N][19],log[N];
    public:
        void init()
        {
            for(int i=1;i<=n;i++)
            {
                f[i][0]=sum[i];
                log[i]=log[i>>1]+1;
            }
            for(int j=1;j<20;j++)
                for(int i=1;i+(1<<j)-1<=n;i++)
                {
                    int x=f[i][j-1],y=f[i+(1<<j-1)][j-1];
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
        return sum[r]-sum[l-1]>sum[k.r]-sum[k.l-1];
    }
};
priority_queue<node>q;
int main()
{
    scanf("%d%d%d%d",&n,&k,&L,&R);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
    st.init();
    for(int i=1;i+L-1<=n;i++)
        q.push(node(i,i+L-1,min(i+R-1,n)));
    while(!q.empty())
    {
        
    }
    return 0;
}