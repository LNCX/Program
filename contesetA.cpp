#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
char s[maxn][maxn];
int cnt,n;
int dx[]={-1,-1,1,1},
    dy[]={-1,1,-1,1};
bool check(int x,int y)
{
    if(s[x][y]=='.') return false;
    for(int i=0;i<4;i++)
    {
        int a=x+dx[i],b=y+dy[i];
        if(a<1||a>n||b<1||b>n) return false;
        if(s[a][b]=='.') return false;
    }
    return true;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(check(i,j))
                cnt++;
    cout<<cnt<<endl;
    return 0;
}