#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long a[maxn],add;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int op,v,x;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d",&v,&x);
            a[v]=(long long)x-add;
        }
        if(op==2)
        {
            scanf("%d",&x);
            add+=(long long)x;
        }
        if(op==3)
        {
            scanf("%d",&x);
            printf("%lld\n",a[x]+add);
        }
    }
}