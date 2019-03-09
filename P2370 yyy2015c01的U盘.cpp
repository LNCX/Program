#include<bits/stdc++.h>
using namespace std;
int f[1005];
struct node
{
    int v,w;
    bool operator<(const node &x) const
    {
        return v<x.v;
    }
}a[1005];
int main()
{
    int n,p,s;
    scanf("%d%d%d",&n,&p,&s);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].v,&a[i].w);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        for(int v=s;v>=a[i].v;v--)
        {
            f[v]=max(f[v],f[v-a[i].v]+a[i].w);
            if(f[s]>=p)
            {
                printf("%d\n",a[i].v);
                return 0;
            }
        }
    puts("No Solution!");
}