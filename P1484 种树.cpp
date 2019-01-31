#include <bits/stdc++.h> 
using namespace std;
const int N=5e5+5;
struct data
{ 
    long long v;
    int id;
    bool operator <(const data &a)const 
    {
        return v<a.v;
    } 
}t;
priority_queue<data>q;
long long a[N],ans;
int l[N],r[N];
bool used[N];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&t.v);
        a[i]=t.v;
        t.id=i;
        l[i]=i-1;
        r[i]=i+1;
        q.push(t);
    }
    r[0]=1;
    l[n+1]=n;
    while(m--)
    {
        while(used[q.top().id])
            q.pop(); 
        t=q.top();q.pop();
        if(t.v<0)break;
        ans+=t.v;
        int x=t.id;
        a[x]=a[l[x]]+a[r[x]]-a[x];
        t.v=a[x];
        used[l[x]]=used[r[x]]=1;
        l[x]=l[l[x]];r[l[x]]=x;
        r[x]=r[r[x]];l[r[x]]=x;
        q.push(t);
    } 
    printf("%lld\n",ans);
}