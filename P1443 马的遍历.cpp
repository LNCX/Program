#include<bits/stdc++.h>
using namespace std;
int b,e=2,a[410][410],pro[160005][2],mx[8]={2,-2,2,-2,-1,1,-1,1},my[8]={1,1,-1,-1,2,2,-2,-2},n,m,x,y;
int main()
{
    cin>>n>>m>>x>>y;
    memset(a,-1,sizeof(a));
    pro[1][0]=x,pro[1][1]=y,a[x][y]=0;
    while(b++<e-1)
    for(int i=0;i<8;i++)
    {
        int xx=pro[b][0]+mx[i],yy=pro[b][1]+my[i];
        if(xx>0&&yy>0&&xx<=n&&yy<=m&&a[xx][yy]==-1)
        pro[e][0]=xx,pro[e++][1]=yy,a[xx][yy]=a[pro[b][0]][pro[b][1]]+1; 
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        	printf("%-5d",a[i][j]);
        cout<<endl;
    }    
    return 0;
} 
