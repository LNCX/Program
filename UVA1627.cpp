#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
#define INF 100000000
vector<int> block[maxn][2];
int tot,d[maxn][2*maxn],b[maxn][2*maxn];
int s[maxn][maxn],g[maxn][maxn],col[maxn],n;
bool dfs(int i,int t,vector<int> *b)
{
    col[i]=t;
    b[t].push_back(i);
    bool ok=true;
    for(int j=1;j<=n;j++)
        if(g[i][j])
        {
            if(col[j]==-1) 
            {
                if(!dfs(j,!t,b))
                {
                    ok=false;
                    break;
                }
            }
            else if(col[j]!=t) continue;
            else
            {
                ok=false;
                break;
            }
        }
    return ok;
}
bool blocks()
{
    for(int i=0;i<maxn;i++)
        for(int j=0;j<2;j++)
            block[i][j].clear();
    tot=0;
    for(int i=1;i<=n;i++)
        if(col[i]==-1)
            if(!dfs(i,0,block[tot++]))
                return false;
    return true;
}
void dp()
{
    memset(d,0,sizeof d);
    memset(b,0,sizeof b);
    for(int i=0;i<=tot;i++)
    {
        for(int j=0;j<2*maxn;j++)
        {
            if(i==0)
            {
                d[i][j]=INF;
                if(j==maxn)
                d[i][j]=0;
                continue;
            }
            d[i][j]=INF;
            int deta=block[i-1][0].size()-block[i-1][1].size();
            if(j-deta>=0&&j-deta<2*maxn&&d[i-1][j-deta]!=INF)
                if(abs(d[i][j])>abs(d[i-1][j-deta]+deta))
                {
                    d[i][j]=d[i-1][j-deta]+deta;
                    b[i][j]=0;
                }
            if(j+deta>=0&&j+deta<2*maxn&&d[i-1][j+deta]!=INF)
                if(abs(d[i][j])>abs(d[i-1][j+deta]-deta))
                {
                    d[i][j]=d[i-1][j+deta]-deta;
                    b[i][j]=1;
                }
        }
    }
}
void print()
{
    int ans=INF,p=0;
    for(int k=0;k<2*maxn;k++)
    {
        if(abs(ans)>abs(d[tot][k]))
        {
            ans=d[tot][k];
            p=k;
        }
    }
    vector<int> col[2];
    for(int i=tot,j=p;i>=0;i--)
    {
        int dt=block[i-1][0].size()-block[i-1][1].size();
        int t=b[i][j];
        if(t==0)
        {
            for(int k=0;k<block[i-1][0].size();k++)
                col[0].push_back(block[i-1][0][k]);
            for(int k=0;k<block[i-1][1].size();k++)
                col[1].push_back(block[i-1][1][k]);
            j-=dt;
        }
        else
        {
            for(int k=0;k<block[i-1][0].size();k++)
                col[1].push_back(block[i-1][0][k]);
            for(int k=0;k<block[i-1][1].size();k++)
                col[0].push_back(block[i-1][1][k]);
            j+=dt;
        }
    }
    printf("%d",int(col[0].size()));
    for(int i=0;i<col[0].size();i++)
    {
        printf(" %d",col[0][i]);
    }
    printf("\n");
    printf("%d",int(col[1].size()));
    for(int i=0;i<col[1].size();i++)
    {
        printf(" %d",col[1][i]);
    }
    printf("\n");
   }
int main() 
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(s,0,sizeof s);
        memset(g,0,sizeof s);
        memset(col,-1,sizeof col);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x;
            while(scanf("%d",&x)&&x)
                s[i][x]=1;
        }
        for(int j=1;j<=n;j++)
            for(int i=1;i<=n;i++)
            {
                if(i==j) continue;
                if(!s[i][j])
                    g[i][j]=g[j][i]=1;
            }
        if(!blocks())
        {
            printf("No solution\n");
            if(t) printf("\n");
            continue;
        }
        dp();
        print();
        if(t) printf("\n");
    }
    return 0;
}