#include<bits/stdc++.h>
using namespace std;
const int N=105,M=6e4+5;
vector< pair<int,int> >a,b;
bool cmp(pair<int,int>x,pair<int,int>y)
{
    return x.first+x.second>y.first+y.second;
}
int n,m,f[N][M],cnt,ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(y>=0) a.push_back(make_pair(x,y));
        else b.push_back(make_pair(x,y));
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end(),cmp);
    for(auto it:a)
    {
        if(m>=it.first) m+=it.second,cnt++;
        else break;
    }
    f[0][m]=cnt;
    for(int i=0;i<b.size();i++)
        for(int j=0;j<=m;j++)
        {
            auto it=b[i];
            if(j>=it.first&&j+it.second>=0)
                f[i+1][j+it.second]=max(f[i+1][j+it.second],f[i][j]+1);
            f[i+1][j]=max(f[i+1][j],f[i][j]);
        }
    for(int i=0;i<=m;i++)
        ans=max(ans,f[b.size()][i]);
    cout<<ans<<endl;
    return 0;
}