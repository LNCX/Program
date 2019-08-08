#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6;
int n,m,cnt;
int u[N],v[N],d[N],f[N],to[N],cut[N];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        d[u[i]]++,d[v[i]]++;
        to[i]=i;
    }
    for(int i=1;i<=n;i++)
        f[i]=(d[i]+1)/2;
    random_shuffle(to+1,to+1+m);
    for(int i=1;i<=m;i++)
        if(d[u[to[i]]]>f[u[to[i]]]&&d[v[to[i]]]>f[v[to[i]]])
            cut[to[i]]=1,cnt++,d[u[to[i]]]--,d[v[to[i]]]--;
    printf("%d\n",m-cnt);
    for(int i=1;i<=m;i++)
        if(!cut[i])
            printf("%d %d\n",u[i],v[i]);
    return 0;
}