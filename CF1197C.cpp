#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int n,k;
ll a[N],ans;
priority_queue< ll,vector<ll>,greater<int> >q;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    ans+=a[n]-a[1];
    for(int i=1;i<n;i++)
        q.push(a[i]-a[i+1]);
    for(int i=1;i<k;i++)
    {
        ans+=q.top();
        q.pop();
    }
    cout<<ans<<endl;
    return 0;
}