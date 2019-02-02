#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int c[500];
int pd[500][500],a[500][500];
int main()
{
    int n,k,m,s,t;
    scanf("%d%d%d%d%d",&n,&k,&m,&s,&t);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=inf;
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=k;i++)
        for(int j=1;j<=k;j++)
            scanf("%d",&pd[i][j]);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(z<a[x][y])
        {
            if(pd[c[x]][c[y]]==0) a[y][x]=z;
            if(pd[c[y]][c[x]]==0) a[x][y]=z;  
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][k]+a[k][j]<a[i][j])
                    a[i][j]=a[i][k]+a[k][j];
    if(c[s]==c[t]||a[s][t]==inf) puts("-1");
    else cout<<a[s][t]<<endl;
    return 0;
}