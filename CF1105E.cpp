#include<bits/stdc++.h>
using namespace std;
const int N=45;
int n,m,g[N][N],ans,cnt[N],q[N];
void link(vector<int>a,int u)
{
    if(u==(int)a.size()) return ;
    for(int v=u+1;v<(int)a.size();v++)
        g[a[u]][a[v]]=g[a[v]][a[u]]=1;
    link(a,u+1);
}
void init()
{
    scanf("%d%d",&n,&m);
    int cnt=0;
    vector<int>a;
    map<string,int>ma;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x==1)
        {
            link(a,0);
            a.clear();
        }
        else
        {
            string s;
            cin>>s;
            if(!ma[s]) ma[s]=++cnt;
            a.push_back(ma[s]);
        }
    }
    link(a,0);
}
bool dfs(int u,int num)
{
    for(int v=u+1;v<=m;v++)
    {
        if(num+cnt[v]<ans) return 0;
        if(!g[u][v])
        {
            int i;
            for(i=0;i<num;i++)
                if(g[v][q[i]]) break;
            if(i==num)
            {
                q[num]=v;
                if(dfs(v,num+1)) return 1;
            }
        }
    }
    if(ans<num)
    {
        ans=num;
        return 1;
    }
    return 0;
}
void bk()
{

    for(int u=m;u>=1;u--)
    {
        q[0]=u;
        dfs(u,1);
        cnt[u]=ans;
    }
    printf("%d\n",ans);
}
int main()
{
    init();
    bk();
    return 0;
}