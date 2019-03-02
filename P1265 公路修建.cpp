#include<bits/stdc++.h>
const int oo=1e9,maxn=5001;
using namespace std;
int p[maxn][2];
double dis[maxn];
bool vis[maxn];
double dist(int x1,int y1,int x2,int y2)
{
    return sqrt((double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2));
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&p[i][0],&p[i][1]);
    for(int i=2;i<=n;i++)
        dis[i]=oo;
    int k;
    double minx,ans=0;
    for(int i=1;i<=n;i++)
    {
        minx=oo;
        for(int j=1;j<=n;j++)
            if(!vis[j]&&dis[j]<minx)
            {
                k=j;
                minx=dis[j];
            }
        ans+=minx;
        vis[k]=true;
        for(int j=1;j<=n;j++)
        {
            double t=dist(p[k][0],p[k][1],p[j][0],p[j][1]);
            if (t<dis[j])
                dis[j]=t;
        }
    }
    printf("%.2lf\n",ans);
    return 0;
}