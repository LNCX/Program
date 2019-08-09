#include<bits/stdc++.h>
#define N 1005
using namespace std;
char a[N][N]={};
bool used[N][N]={0};
int n,m,ans[N][N],que[N*N][2]={0},
    dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0};
int dfs(int x,int y)
{
    int head=0,tail=1;
    que[1][0]=x,que[1][1]=y;
    used[x][y]=true;
    while(head<=tail)
    {
        head++;
        for(int i=1;i<=4;i++)
        {
            int tx=que[head][0]+dx[i],ty=que[head][1]+dy[i];
            if(a[tx][ty]!=a[que[head][0]][que[head][1]]&&!used[tx][ty])
            if(0<=tx&&tx<n&&0<=ty&&ty<n)
            {
                tail++;
                que[tail][0]=tx,que[tail][1]=ty;
                used[tx][ty]=true;
            }
        }
    }
    for(int i=1;i<=tail;i++)
        ans[que[i][0]][que[i][1]]=tail;	
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)	
        cin>>a[i];
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        if(used[i][j]==false)
            dfs(i,j);
    while(m--)
    {
        int i,j;
        scanf("%d%d",&i,&j);
        cout<<ans[i-1][j-1]<<endl;
    }
}
