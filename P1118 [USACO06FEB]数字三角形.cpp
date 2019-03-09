#include<bits/stdc++.h>
using namespace std;
bool v[13];
int n,sum,flag,a[13][13],b[13];
void print()
{
    for(int i=1;i<=n;i++)
        printf("%d ",b[i]);
}
void dfs(int s,int ans)
{
    if(ans>sum||flag)return;
    if(s>n&&ans==sum)
    {
        print();
        flag=1;
        return;
    }
    for(int i=1;i<=n;i++)
        if(!v[i])
        {
            b[s]=i;
            v[i]=true;
            dfs(s+1,ans+i*a[n][s]);
            v[i]=false;
        }
}

int main()
{
    scanf("%d%d",&n,&sum);
    a[1][1]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];
    dfs(1,0);
    return 0;
}