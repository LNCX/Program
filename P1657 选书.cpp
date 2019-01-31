#include<bits/stdc++.h>
using namespace std;
int n,ans,a[25][2],used[25];
void dfs(int now)
{
    if(now>n){ans++;return;}
    for(int i=0;i<2;i++)
        if(!used[a[now][i]])
        {
            used[a[now][i]]=1;
            dfs(now+1);
            used[a[now][i]]=0;
        }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i][0],&a[i][1]);
    dfs(1);
    if(n==0) ans=0;
    cout<<ans<<endl;
}