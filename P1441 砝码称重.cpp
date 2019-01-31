#include<bits/stdc++.h>
using namespace std;
bool used[25];
int ans,sum,n,m,a[25],b[25];
void dp()
{
    int cnt=0,tot=0;
    bool f[2005]={true};
    for(int i=0;i<n;i++)
    {
        if(used[i]) continue;
        for(int v=tot;v>=0;v--)
            if(!f[v+a[i]]&&f[v])
            {
                f[v+a[i]]=true;
                cnt++;
            }
        tot+=a[i];
    }
    ans=max(cnt,ans);
}
void dfs(int step,int now)
{
    if(now>m)return;
    if(step==n){if(now==m)dp();return;}
    dfs(step+1,now);
    used[step]=true;
    dfs(step+1,now+1);
    used[step]=false; 
} 
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    dfs(0,0);
    cout<<ans<<endl;
}
