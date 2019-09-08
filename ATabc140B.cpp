#include<bits/stdc++.h>
using namespace std;
const int N=25;
int a[N],b[N],c[N],ans;
int main()
{
    int  n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i< n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
    {
        ans+=b[a[i]];
        if(a[i-1]+1==a[i]&&a[i-1]!=0)
            ans+=c[a[i-1]];
    }
    cout<<ans<<endl;
    return 0;
}