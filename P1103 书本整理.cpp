#include<bits/stdc++.h>
using namespace std;
const int N=105,inf=0x3f3f3f3f;
struct node
{
    int h,w;
    bool operator<(const node x)const
    {
        return h<x.h;
    }
}a[N];
int ans=inf,f[N][N];//放i本书，最后一本是j,f[i][j]=min{f[i-1][k]+abs(a[k].w-a[j].w)}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].h,&a[i].w);
    sort(a+1,a+1+n);
    memset(f,inf,sizeof(f));
    for(int i=1;i<=n;i++) f[1][i]=0;
    for(int i=2;i<=n-m;i++)
        for(int j=1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                f[i][j]=min(f[i][j],f[i-1][k]+abs(a[k].w-a[j].w));
    for(int i=1;i<=n;i++)
        ans=min(f[n-m][i],ans);
    cout<<ans<<endl;
    return 0;
}