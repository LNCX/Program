#include<bits/stdc++.h>
using namespace std;
const int maxn=2e+5;
struct node
{
    int p,l;
}a[maxn];
struct line
{
    int l,r,f;
};
vector<line>b;
int f[maxn];
int find(int x)
{
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}
int main()
{
    int n,q;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].p,&a[i].l);
    scanf("%d",&q);
    
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        for(int i=0;i<b.size();i++)
        {
            if(find(x)==b[i].f)
            {
                
            }
        }    
    }
    return 0;
}