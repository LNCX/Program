#include<bits/stdc++.h>
using namespace std;
const int N=205;
string s[3];
int n,tot,ans;
vector<int>e[N];
map<string,int>ma;
void dfs(int u,int len)
{
    ans=max(len,ans);
    for(auto v:e[u])
        dfs(v,len+1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
            cin>>s[j],transform(s[j].begin(),s[j].end(),s[j].begin(),::tolower);;
        int u=(ma[s[2]]==0?ma[s[2]]=++tot:ma[s[2]]);
        int v=(ma[s[0]]==0?ma[s[0]]=++tot:ma[s[0]]);
        e[u].push_back(v);
    }
    int rt=ma["polycarp"];
    dfs(rt,1);
    cout<<ans<<endl;
    return 0;
}