#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000+5;
int n,m,p,vis[maxn][maxn],ans[maxn],s[maxn];
char a[maxn][maxn];
struct node
{
   int x,y,cnt;
};
queue<node>boder[10],q;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
void bfs(int u)
{
    node tmp;
    int x,y;
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        if(tmp.cnt==0) boder[u].push(tmp);
        else
        {
            for(int i=0;i<4;i++)
            {
                x=tmp.x+dir[i][0];
                y=tmp.y+dir[i][1];
                if(x<1||y<1||x>n||y>m||a[x][y]!='.'||vis[x][y]!=0) continue;
                vis[x][y]=u;
                q.push(node{x,y,tmp.cnt-1}); 
            }
        } 
    }
    return ;
}
bool expand(int u)
{
    node tmp;
    while(!boder[u].empty())
    {
        tmp=boder[u].front();   
        boder[u].pop();
        tmp.cnt=s[u];
        q.push(tmp);
    }    
    bfs(u);
    return !boder[u].empty();
} 
int main()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=p;i++)  scanf("%d",&s[i]);
    for(int i=1;i<=n;i++)  scanf("%s",a[i]+1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]>='0'&&a[i][j]<='0'+p)
            {
                int num=a[i][j]-'0';
                boder[num].push(node{i,j,s[num]}); 
                vis[i][j]=num;
            }
        }
    }
    while(1)
    {
        bool ok=false;
        for(int i=1;i<=p;i++)
            ok|=expand(i);  
        if(!ok) break;    
    }
     for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            ans[vis[i][j]]++;
    for(int i=1;i<=p;i++)
        printf("%d ",ans[i]);
    return 0;
}