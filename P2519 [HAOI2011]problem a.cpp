#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,i,a,b,f[maxn];
vector<int>len[maxn];
map<pair<int,int>,int>s;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a,&b);
        ++a,b=n-b;
        if(a>b) continue;
        if(++s[make_pair(a,b)]==1)
            len[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1];
        for(int j=0;j<(int)len[i].size();j++)
            f[i]=max(f[i],f[len[i][j]-1]+min(i-len[i][j]+1,s[make_pair(len[i][j],i)]));
    }
    printf("%d\n",n-f[n]);
    return 0;
}