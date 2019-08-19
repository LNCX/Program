#include<bits/stdc++.h>
using namespace std;
const int N=205;
int a[N],b[N],vis[N];
int main()
{
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),vis[a[i]]=1;
    cin>>m;
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]),vis[b[i]]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(!vis[a[i]+b[j]])
            {
                printf("%d %d\n",a[i],b[j]);
                return 0;
            }
    return 0;
}