#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,b,c,d,num;
    bool operator<(const node&k)const
    {
        if(a!=k.a) return a<k.a;
        if(b!=k.b) return b<k.b;
        if(c!=k.c) return c<k.c;
        return d<k.d;
    }
}p,f;
int r,c;
char a[32][32];
int dx[4]={1,-1,0,0},
    dy[4]={0,0,1,-1};
queue<node>q;
map<node,bool>v;
void bfs()
{
    v[p]=1;
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            f=p;
            f.a+=dx[i],f.b+=dy[i];
            f.c+=dx[i],f.d-=dy[i];
            f.num++;
            if(a[f.a][f.b]=='#') f.a-=dx[i],f.b-=dy[i];
            if(a[f.c][f.d]=='#') f.c-=dx[i],f.d+=dy[i];
            if(a[f.a][f.b]=='T'&&a[f.c][f.d]=='T')
                return (void)printf("%d\n",f.num);
            if(f.a<=r&&f.b<=c&&f.c<=r&&f.d<=c)
                if(f.a>=1&&f.b>=1&&f.c>=1&&f.d>=1)
                    if(a[f.a][f.b]!='X'&&a[f.c][f.d]!='X')
                        if(!v[f]) v[f]=1,q.push(f);
        }
    }
    return (void)puts("no");
}
int main()
{
    scanf("%d%d",&r,&c);
    for(int i=1;i<=r;i++)
        scanf("%s",a[i]+1);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
        {
            if(a[i][j]=='G') p.a=i,p.b=j;
            if(a[i][j]=='M') p.c=i,p.d=j;
        }
    bfs();
}