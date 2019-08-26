#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
map<int,int>ma,em;
int a[N],sum,ans=N;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),ma[a[i]]++;
    em=ma;
    for(auto it:ma)
        if(it.second>1)
            sum++;
    if(sum==0) ans=0;
    for(int l=1;l<=n;l++)
    {
        ma=em;
        int cnt=sum;
        for(int r=l;r<=n;r++)
        {
            ma[a[r]]--;
            if(ma[a[r]]==1) cnt--;
            if(cnt==0)
            {
                ans=min(r-l+1,ans);
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}