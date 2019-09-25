#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=505,inf=0x3f3f3f3f;
int cnt,vis[maxn],add[maxn];
LL dis[maxn][maxn],ans[maxn];
int main()
{
    int n;
    cin>>n;
    memset(dis,inf,sizeof(dis));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%I64d",&dis[i][j]);
    for(int i=1;i<=n;i++)
        scanf("%d",&add[i]);
    for(int k=n;k>=1;k--)
    {
        int s=add[k];
        vis[s]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)  
                if(dis[i][j]>dis[i][s]+dis[s][j])
                    dis[i][j]=dis[i][s]+dis[s][j];
            LL sum=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    if(vis[i]==false||vis[j]==false)
                        continue;
                    sum+=dis[i][j];
                }
            ans[cnt++]=sum;
    }
    for(int i=cnt-1;i>=0;i--)
        printf("%I64d ",ans[i]);
    puts("");
    return 0;
}