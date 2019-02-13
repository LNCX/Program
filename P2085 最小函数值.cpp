#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int maxn=10005;
int a[maxn],b[maxn],c[maxn],cnt;
LL f(int i,int x)
{
    return (LL)a[i]*x*x+b[i]*x+c[i];
}
struct node
{
    int i,x;
    friend bool operator<(const node x,const node y)
    {
        return f(x.i,x.x)>f(y.i,y.x);
    }
};
priority_queue<node>q;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        q.push((node){i,1});
    }
    while(cnt<m)
    {
        node mid=q.top();q.pop();
        int i=mid.i,x=mid.x;
        printf("%lld ",f(i,x));
        q.push((node){i,x+1});
        cnt++;
    }
    return 0;
}