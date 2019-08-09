#include<bits/stdc++.h>
using namespace std;
#define N 41
int f[N][N][N][N],num[351],g[5],n,m,x;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    f[0][0][0][0]=num[1];
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        g[x]++;
    }
    for(int a=0;a<=g[1];a++)
    for(int b=0;b<=g[2];b++)
    for(int c=0;c<=g[3];c++)
    for(int d=0;d<=g[4];d++)
    {
        int r=1+a+b*2+c*3+d*4;
        if(a!=0)    f[a][b][c][d]=max(f[a][b][c][d],f[a-1][b][c][d]+num[r]);
        if(b!=0)    f[a][b][c][d]=max(f[a][b][c][d],f[a][b-1][c][d]+num[r]);
        if(c!=0)    f[a][b][c][d]=max(f[a][b][c][d],f[a][b][c-1][d]+num[r]);
        if(d!=0)    f[a][b][c][d]=max(f[a][b][c][d],f[a][b][c][d-1]+num[r]);
    }   
    cout<<f[g[1]][g[2]][g[3]][g[4]];
}
