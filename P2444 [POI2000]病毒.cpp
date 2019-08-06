#include<bits/stdc++.h>
using namespace std;
const int N=3e4+5;
char s[N];
bool bo[N],vis[N],ins[N];
int nxt[N],ch[N][2],tot=1,n;
void insert(char *s)
{
    int len=strlen(s),u=1;
    for(int i=0;i<len;i++)
    {
        int c=s[i]-'0';
        if(!ch[u][c]) ch[u][c]=++tot;
        u=ch[u][c];
    }
    bo[u]=1;
}
void build()
{
    queue<int>q;q.push(1);
    ch[0][0]=ch[0][1]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int c=0;c<2;c++)
        {
            if(!ch[u][c]) ch[u][c]=ch[nxt[u]][c];
            else
            {
                nxt[ch[u][c]]=ch[nxt[u]][c];
                bo[ch[u][c]]|=bo[nxt[ch[u][c]]];
                q.push(ch[u][c]);
            }
        }
    }
}
void dfs(int u)
{
    if(ins[u])
    {
        puts("TAK");
        exit(0);
    }
    if(bo[u]||vis[u]) return;
    vis[u]=ins[u]=1;
    dfs(ch[u][0]);
    dfs(ch[u][1]);
    ins[u]=0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s);
        insert(s);
    }
    build();
    dfs(1);
    puts("NIE");
    return 0;
}