#include<iostream>
using namespace std;
bool a[22][22];
long long f[22][22];
int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    f[1][1]=1;
    m+=1,n+=1,x+=1,y+=1; 
    if(x+1>=0&&y-2>=0)a[x+1][y-2]=1;
    if(x+1>=0&&y+2>=0)a[x+1][y+2]=1;
    if(x+2>=0&&y+1>=0)a[x+2][y+1]=1;
    if(x+2>=0&&y-1>=0)a[x+2][y-1]=1;
    if(x-1>=0&&y-2>=0)a[x-1][y-2]=1;
    if(x-1>=0&&y+2>=0)a[x-1][y+2]=1;
    if(x-2>=0&&y-1>=0)a[x-2][y-1]=1;
    if(x-2>=0&&y+1>=0)a[x-2][y+1]=1;
    a[x][y]=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(!a[i][j]) f[i][j]+=f[i-1][j]+f[i][j-1];
            else f[i][j]=0;
        }
    cout<<f[n][m]<<endl;
}

