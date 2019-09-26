#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,cnt[N][5],w[N],ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        char s[N];
        scanf("%s",s+1);
        for(int k=1;k<=m;k++)
            cnt[k][s[k]-'A']++;
    }
    for(int i=1;i<=m;i++)
        scanf("%d",&w[i]);
    for(int i=1;i<=m;i++)
    {
        int mid=0;
        for(int j=0;j<5;j++)
            mid=max(cnt[i][j],mid);
        ans+=mid*w[i];
    }
    cout<<ans<<endl;
    return 0;
}