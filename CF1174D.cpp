#include<bits/stdc++.h>
using namespace std;
const int N=(1<<18)+5;
vector<int>ans;
int n,x,a[N],vis[N];
int main()
{
    scanf("%d%d",&n,&x);
    vis[x]=vis[0]=1,ans.push_back(0);
    for(int i=1;i<(1<<n);i++)
    {
        if(!vis[i])
        {
            if(vis[i^x]) continue;
            vis[i]=1;
            ans.push_back(i);
        }
    }
    printf("%d\n",ans.size()-1);
    for(int i=1;i<ans.size();i++)
        printf("%d ",ans[i]^ans[i-1]);
    return 0;
}