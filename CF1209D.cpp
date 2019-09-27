#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,f[N],cnt;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        f[find(x)]=find(y);
    }
    for(int i=1;i<=n;i++)
        if(f[i]==i)
            cnt++;
    cout<<m-(n-cnt)<<endl;
    return 0;
}