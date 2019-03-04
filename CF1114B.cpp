#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct node
{
    int num,r;
    bool operator<(const node x) const 
    {
        return num>x.num;
    }
}a[maxn];
long long ans;
bool b[maxn];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].num);
        a[i].r=i;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=m*k;i++)
    {   
        b[a[i].r]=1;
        ans+=a[i].num;
    }
    cout<<ans<<endl;
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]) cnt1++;
        if(cnt1==m)
        {
            printf("%d ",i);
            cnt1=0;
            cnt2++;
        }
        if(cnt2==k-1) break;
    }
    return 0;
}