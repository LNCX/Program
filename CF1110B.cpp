#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,k,m,ans,b[maxn];
priority_queue<int>q;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(int i=2;i<=n;i++)
        q.push(-(b[i]-b[i-1]));        
    ans=n;
    if(n<=k)
    {
        cout<<ans<<endl;
        return 0;
    }
    while(n>k)
    {
        ans+=(-q.top())-1;
        q.pop();
        n--;
    }
    cout<<ans<<endl;
    return 0;
}