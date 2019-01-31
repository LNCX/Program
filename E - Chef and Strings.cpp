# include <bits/stdc++.h>
using namespace std;
char s[100003][13];
char ans[100003][13];
struct Query
{
    int r, id;
    char s[13];
}a[100003];
int node[1000003][26]={0}, cnt=0, id, l;
bool tail[1000003]={false};
bool cmp(Query x, Query y){return x.r < y.r;}
void add(char st[])
{
    int len = strlen(st), cur = 0;
    for(int i=0; i<len; ++i)
    {
        int to = st[i]-'a';
        if(node[cur][to] == 0) node[cur][to] = ++cnt;
        cur = node[cur][to];
    }
    tail[cur] = 1;
}
void dfs(int cur)
{
    if(tail[cur]) return;
    for(int i=0; i<26; ++i)
    {
        if(node[cur][i])
        {
            ans[id][l++] = i+'a';
            dfs(node[cur][i]);
            break;
        }
    }
}
void query(char st[])
{
    int len = strlen(st),cur=0;
    for(int i=0; i<len; ++i)
    {
        int to = st[i]-'a';
        if(node[cur][to])
        {
            ans[id][l++] = to+'a';
            cur = node[cur][to];
        }
        else break;
    }
    dfs(cur);
}
int main()
{
    int n, q;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%s",s[i]);
    scanf("%d",&q);
    for(int i=1; i<=q; ++i) scanf("%d%s",&a[i].r,a[i].s), a[i].id=i;
    sort(a+1,a+1+q,cmp);
    int k = 1;
    for(int i=1; i<=q; ++i)
    {
        while(k<=a[i].r) add(s[k++]);
        id = a[i].id;
        l = 0;
        query(a[i].s);
        ans[id][l] = '\0';
    }
    for(int i=1; i<=q; ++i)
        puts(ans[i]);
    return 0;
}
