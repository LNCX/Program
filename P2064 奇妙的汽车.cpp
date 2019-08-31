#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int ans=inf,s;
void dfs(int x,int s)
{
    if(s==0)
    {
        ans=min(ans,(x<2)?inf:x);
        return ;
    }
    s--;
    for(int i=2;i<=9;i++)
        if(s%i==0)
            dfs(x+1,s/i);
}
int main()
{
    scanf("%d",&s);
    for(int i=1;i*i<=s;i++)
        if(s%i==0)
        {
            dfs(0,i);
            dfs(0,s/i); 
        }
    ans==inf?puts("-1"):printf("%d\n",ans);
    return 0;
}