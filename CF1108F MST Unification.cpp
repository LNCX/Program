#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
int n,m,fa[maxn],ans;
struct edge
{
    int x,y,z;
    bool operator<(const edge w)const
    {
        return z<w.z;
    }
}a[maxn];
int get(int x)
{
    if(x==fa[x])return x;
    return fa[x]=get(fa[x]);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
    sort(a+1,a+m+1);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1,j=1;i<=m;i=j)
    {
        while(j<=m&&a[j].z==a[i].z)
            j++;
        int cnt=j-i;
        for(int k=i;k<j;k++)
        {
            int x=get(a[k].x),y=get(a[k].y);
            if(x==y)
                cnt--;
        }
        for(int k=i;k<j;k++)
        {
            int x=get(a[k].x),y=get(a[k].y);
            if(x==y)continue;
            cnt--;
            fa[x]=y;
        }
        ans+=cnt;
    }
    cout<<ans<<endl;
    return 0;
}