#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int N=1e5+5;
int n,m,c[N][2];
void add(int x,int y)
{
    while(x<=n)
    {
        c[x][y]++;
        x+=lowbit(x);
    }
}
int ask(int x,int y)
{
    int res=0;
    while(x>0)
    {
        res+=c[x][y];
        x-=lowbit(x);
    }
    return res;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int q,l,r;
        scanf("%d%d%d",&q,&l,&r);
        if(q==1) add(l,0),add(r,1);
        else printf("%d\n",ask(r,0)-ask(l-1,1));
    }
    return 0;
}