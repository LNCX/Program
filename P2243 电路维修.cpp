#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=505;
char map[N][N];
bool used[N][N];
int dx[4]={1,1,-1,-1},
    dy[4]={1,-1,1,-1};
int n,m,dis[N][N];
deque< pair<int,int> >q,empty;
bool turn(int x1,int y1,int x2,int y2)
{
    int x=map[(x1+x2)/2][(y1+y2)/2]=='/'?1:-1;
    return x==(y1-y2)/(x1-x2);
}
void bfs()
{
    memset(used,0,sizeof(used));
    memset(dis,0x3f3f3f3f,sizeof(dis));
    q=empty;q.push_back(make_pair(0,0));dis[0][0]=0;
    while(!q.empty())
    {
        int a=q.front().first,
            b=q.front().second;
        q.pop_front();used[a][b]=true;
        for(int i=0;i<4;i++)
        {
            int x=dx[i]+a,y=dy[i]+b;
            if(x<0||n<x||y<0||m<y||used[x][y])
                continue;
            if(turn(a,b,x,y))
            {
                dis[x][y]=min(dis[x][y],dis[a][b]+1);
                q.push_back(make_pair(x,y));
            }
            else
            {
                dis[x][y]=min(dis[x][y],dis[a][b]);
                q.push_front(make_pair(x,y));
            }
            if(x==n&&y==m) return;
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",map[i]);
        if((n+m)%2)
        {
            puts("NO SOLUTION");
            continue;
        }
        bfs();
        printf("%d\n",dis[n][m]);
    }
    return 0;
}