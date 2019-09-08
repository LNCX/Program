#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int p[N],n;
long long ans=0;
class RMQ
{
    private:
        pair<int,int> f[N][20];
        int log[N]={-1};
    public:
        RMQ(){memset(f,-0x3f3f3f3f,sizeof(f));}
        void insert()
        {
            for(int i=1;i<=n;i++)
            {
                log[i]=log[i>>1]+1;
                f[i][0].first=p[i],f[i][0].second=i;
            }
            for(int j=1;(1<<j)<=n;j++)
                for(int i=1;i+(1<<j)-1<=n;i++)
                    f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
        int query(int l,int r)
        {
            int k=log[r-l+1];
            return max(f[l][k],f[r-(1<<k)+1][k]).second;
        }
}st;
int find1(int x,int now)
{
    int l=1,r=x,res=0;
    while(l<=r)
    {
        int mid=(l+r)>>1,k=st.query(mid,x);
        if(p[k]>now) res=k,l=mid+1;
        else r=mid-1;
    }
    return res;
}
int find2(int x,int now)
{
    int l=x,r=n,res=n+1;
    while(l<=r)
    {
       int mid=(l+r)>>1,k=st.query(x,mid); 
       if(p[k]>now) res=k,r=mid-1;
       else l=mid+1;
    }
    return res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    st.insert();
    for(int i=1;i<=n;i++)
    {
        int a=find1(i-1,p[i]);
        int b=find1(a-1,p[i]);
        int c=find2(i+1,p[i]);
        int d=find2(c+1,p[i]);
        ans+=(long long)((a-b)*(c-i)+(i-a)*(d-c))*p[i];
    }
    cout<<ans<<endl;
    return 0;
}