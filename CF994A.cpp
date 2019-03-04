#include<bits/stdc++.h>
using namespace std;
const int maxn=15;
int a[maxn],b[maxn],c[maxn],vis[maxn];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j]&&!vis[j])
            {
                vis[j]=1;
                c[i]=1;
            }
    for(int i=1;i<=n;i++)
        if(c[i])
            printf("%d ",a[i]);
    puts("");
    return 0;
}