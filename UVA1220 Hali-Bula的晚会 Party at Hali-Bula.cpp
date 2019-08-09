#include<bits/stdc++.h>
using namespace std;
const int N=205;
vector<int> G[N];
bool f[N][2];
int d[N][2], n, cnt;
map<string, int> Map;
void init()
{
    for(int i = 1; i <= n; ++i)  G[i].clear();
    memset(f, false, sizeof(f));
    memset(d, 0, sizeof(d));
    cnt = 0;   Map.clear();
}
int getid(const string &s)
{
    if(Map.count(s))   return Map[s];
    return Map[s] = ++cnt;
}
void dfs(int u)
{
    if(!G[u].size())
    {
        d[u][0] = 0;
        d[u][1] = 1;
        return ;
    }
    for(int i = 0; i < G[u].size(); ++i)
    {
        int son = G[u][i];
        dfs(son);
        d[u][1] += d[son][0];
        if(f[son][0])   f[u][1] = true;
        if(d[son][0] > d[son][1])
        {
            d[u][0] += d[son][0];
            if(f[son][0])  f[u][0] = true;
        }
        else if(d[son][0] == d[son][1])
        {
            d[u][0] += d[son][0];
            f[u][0] = true;
        }
        else {
            d[u][0] += d[son][1];
            if(f[son][1])  f[u][0] = true;
        }
    }
    ++d[u][1];
}
int main()
{
    while(scanf("%d", &n) == 1 && n)
    {
        init();
        string s1, s2;
        cin >> s1;  getid(s1);
        for(int i = 0; i < n-1; ++i)
        {
            cin >> s1 >> s2;
            G[getid(s2)].push_back(getid(s1));
        }
 
        dfs(1);
        if(d[1][0] == d[1][1])  printf("%d No\n", d[1][0]);
        else if(d[1][0] > d[1][1])  printf("%d %s\n", d[1][0], f[1][0] ? "No" : "Yes");
        else  printf("%d %s\n", d[1][1], f[1][1] ? "No" : "Yes");
    }
    return 0;
}