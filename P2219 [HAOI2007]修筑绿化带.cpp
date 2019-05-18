#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
deque<int>q[maxn],Q;
int m,n,a,b,c,d,ans;
int num[maxn][maxn],sum[maxn][maxn];
inline int calc1(int x,int y)
{
    return sum[x+c-1][y+d-1]-sum[x-1][y+d-1]-sum[x+c-1][y-1]+sum[x-1][y-1];
}
inline int calc2(int x,int y)
{
    return sum[x+a-1][y+b-1]-sum[x-1][y+b-1]-sum[x+a-1][y-1]+sum[x-1][y-1];
}
int main()
{
    scanf("%d%d%d%d%d%d",&m,&n,&a,&b,&c,&d);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&num[i][j]);
            sum[i][j]=num[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    for(int i=2;i<=n-d;i++)
    {
        for(int j=2;j<=m-c;j++)
        {
            if(!q[j].empty()&&q[j].front()==i+d-b+1)
                q[j].pop_front();
            while(!q[j].empty()&&calc1(j,q[j].back())>=calc1(j,i))
                q[j].pop_back();
            q[j].push_back(i);
        }
        if(i+d-b>=0)
        {
            Q.clear();
            for(int k=2;k<=m-c;k++)
            {
                if(!Q.empty()&&k+c-a+1==Q.front())
                    Q.pop_front();
                while(!Q.empty()&&calc1(Q.back(),q[Q.back()].front())>=calc1(k,q[k].front()))
                    Q.pop_back();
                Q.push_back(k);
                if(k+c-a>=0)
                    ans=max(ans,calc2(k+c-a+1,i+d-b+1)-calc1(Q.front(),q[Q.front()].front()));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}