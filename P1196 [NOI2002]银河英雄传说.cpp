#include<bits/stdc++.h>
using namespace std;
const int N=30001;
int fa[N],dis[N],t,cnt[N];
int find(int x)
{
    if(x!=fa[x])
    {
        int k=fa[x];
        fa[x]=find(fa[x]);
        dis[x]+=dis[k];
        cnt[x]=cnt[fa[x]];
    }
    return fa[x];
}
void merge(int x,int y)
{
    int r1=find(x),r2=find(y);
    if(r1!=r2)
    {
        fa[r1]=r2;
        dis[r1]=dis[r2]+cnt[r2];
        cnt[r2]+=cnt[r1];
        cnt[r1]=cnt[r2];
    }
}
int query(int a,int b)
{
    int r1=find(a),r2=find(b);
    if(r1!=r2) return -1;
    else return abs(dis[a]-dis[b])-1;
}
int main()
{
    scanf("%d",&t);
    for(int i=1;i<N;i++) 
        fa[i]=i,cnt[i]=1;
    for(int i=1;i<=t;i++)
    {
        char c[2];
        int a,b;
        scanf("%s%d%d",c,&a,&b);
        if(*c=='M') merge(a,b);
        else printf("%d\n",query(a,b));
    }
    return 0;
}