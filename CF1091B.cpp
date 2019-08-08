#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
map<pair<int,int>,int>cnt;
int x[N],y[N],a[N],b[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cnt[make_pair(x[i]+a[j],y[i]+b[j])]++;
            if(cnt[make_pair(x[i]+a[j],y[i]+b[j])]==n)
            {
                printf("%d %d\n",x[i]+a[j],y[i]+b[j]);
                return 0;
            }
        }
    return 0;
}