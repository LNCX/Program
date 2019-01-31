#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int q[maxn*maxn][2],
    dx[4]={1,-1,0,0},
    dy[4]={0,0,1,-1};
bool used[maxn][maxn],
     vis[maxn][maxn];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        bool flag=false;
        int n,l=0,r=1,cnt=0;
        cin>>n;
        q[1][0]=q[1][1]=1;
        memset(used,0,sizeof(used));
        memset(vis,0,sizeof(vis));
        while(l<=r)
        {
            l++;
            while(used[q[l][0]][q[l][1]]&&l<r) l++;
            if(l>r) break;
            for(int i=0;i<4;i++)
            {
                int a=q[l][0]+dx[i],b=q[l][1]+dy[i];
                if(0<a&&0<b&&a<=n&&b<=n&&!used[a][b]&&!vis[a][b])
                    q[++r][0]=a,q[r][1]=b;
            }
            if(cnt++<2*n-2)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                used[x][y]=true;
            }
            vis[q[l][0]][q[l][1]]=true;
            if(vis[n][n])
            {
                flag=1;
                break;
            }
        }
        flag==1||n==1?puts("Yes"):puts("No");
    }
}