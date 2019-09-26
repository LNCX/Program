#include<bits/stdc++.h>
using namespace std;
const int M=105;
int m,n,a[M][M];
struct node
{
    int x,y,cnt;
};
int bfs()
{




    return -1;
}
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
    {
        int x,y,c;
        scanf("%d%d%d",&x,&y,&c);
        a[x][y]=c;
    }
    cout<<bfs()<<endl;
    return 0;
}