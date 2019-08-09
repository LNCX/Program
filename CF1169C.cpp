#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m;
vector<int>a;
bool check(int op)
{
    int p=0;
    for(auto x:a)
    {
        if(x<p)
        {
            if(x+op<p) return false;
            else p=p;
        }
        if(x>p)
        {
            if(m-(x-p)<=op) continue;
            else p=x;
        }
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        a.push_back(x);
    }
    int l=0,r=m,ans=m;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        cerr<<l<<" "<<r<<" "<<check(mid)<<endl;
        if(check(mid)) r=mid-1,ans=mid;
        else l=mid+1;
    }
    cout<<ans<<endl;
    return 0;
}