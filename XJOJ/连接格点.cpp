#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e6+10;
int f[N],n,m,x,y,k,ans,x1,y1,x2,y2;
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n*m;i++)f[i]=i; 
    while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2)==4)
    {
        x=(x1-1)*m+y1;
        y=(x2-1)*m+y2;
        x=find(x);y=find(y);
        if(x!=y)f[y]=x;
    }
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n-1;i++)
        {
            x=find((i-1)*m+j);
            y=find(i*m+j);
            if(x!=y)
                f[y]=x,ans++;
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m-1;j++)
        {
            x=find((i-1)*m+j);
            y=find((i-1)*m+j+1);
            if(x!=y) 
                f[y]=x,ans+=2;
    }
    printf("%d\n",ans);
}