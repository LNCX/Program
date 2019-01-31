#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+5;
int x[maxn],y[maxn],ans;
bool line[maxn],used[maxn];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        line[x[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(line[i]) continue;
        int tot=0;
        memset(used,false,sizeof(used));
        for(int j=1;j<=k;j++)
        {
            if(!used[y[j]])
            {
                used[y[j]]=1;
                tot++;
            }
            int t=y[j]-(x[j]-i);
            if(1<=t&&t<=m)
                if(!used[t])
                {
                    used[t]=1;
                    tot++;
                }
            t=y[j]+(x[j]-i);
            if(1<=t&&t<=m)
                if(!used[t])
                {
                    used[t]=1;
                    tot++;
                }
        }
        ans+=m-tot; 
    }
    printf("%d\n", ans);
    return 0;
}