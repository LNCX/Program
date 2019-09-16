#include<bits/stdc++.h>
using namespace std;
int n,ans,a[110];
bool vis[110];
signed main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            ans++;
            vis[i]=true;
            for(int j=i+1;j<=n;j++)
                if(a[j]%a[i]==0)
                    vis[j]=true;
        }
    printf("%d\n",ans);
    return 0;
}