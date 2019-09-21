#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
queue<ll>q;
const int siyuan=998244353;
ll mod(ll a){return (a%siyuan+siyuan)%siyuan;}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    ll sum=1;
    if(n==1) return printf("1"),0;
    for(int i=1;i<=m;i++)
        q.push(0);
    q.push(1);
    for(int i=2;i<=n;i++)
    {
        ll x=q.front();
        q.push(sum);
        sum=mod(2*sum);
        if(i==m) sum=mod(sum-1);
        sum=mod(sum-x);
        q.pop();
    }
    cout<<sum<<endl;
    return 0;
}
