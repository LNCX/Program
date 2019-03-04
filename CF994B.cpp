#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
struct node
{
    LL pow,mon,get,id;
    node():get(0) {}
}  a[maxn];
bool operator<(node a,node b)
{return a.mon<b.mon;}
bool cmp1(node a,node b)
{return a.pow<b.pow;}
node temp[maxn];
LL res[maxn];
priority_queue<node> q;
int main()
{
    LL n,k;
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i].pow);
        a[i].id=i;
    }
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i].mon);
    sort(a,a+n,cmp1);
    for(int i=0;i<n;i++)
    {
        if(i!=0)
            q.push(a[i-1]);
        LL cnt=0;
        while(!q.empty()&&cnt<k)
        {
            temp[cnt]=q.top();
            a[i].get+=temp[cnt].mon;
            q.pop();
            cnt++;
        }
        for(int j=0;j<cnt;j++)
            q.push(temp[j]);
        res[a[i].id]=a[i].get+a[i].mon;
    }
    for(int i=0;i<n;i++)
        printf("%lld ",res[i]);
    return 0;
}
