#include<bits/stdc++.h>
using namespace std;
int f[205][205],w[105],c[105];
int main()
{
    int n,m,T;
    scanf("%d%d%d",&n,&m,&T);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&w[i],&c[i]);
    for(int i=1;i<=n;i++)
        for(int v=m;v>=w[i];v--)
            for(int t=T;t>=c[i];t--)
                f[v][t]=max(f[v][t],f[v-w[i]][t-c[i]]+1);
    cout<<f[m][T]<<endl;
    return 0;
}