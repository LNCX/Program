#include<bits/stdc++.h>
using namespace std;
int n,used[10],ans[10];
void print()
{
    for(int i=1;i<=n;i++)
        printf("%5d",ans[i]);
    printf("\n");
}
void dfs(int x)
{
    if(x>n){print();return;}
    for(int i=1;i<=n;i++)
        if(!used[i])
        {
            used[i]=true;
            ans[x]=i;
            dfs(x+1);
            ans[x]=0;
            used[i]=false;
        }
}
int main()
{
    cin>>n;
    dfs(1);	
}
