#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=100005;
int f[1<<20],a[maxn];
int main() 
{
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int x=0;
        if(!f[a[i]])
        {
            f[a[i]]=1;
            ans++;
        }
        for(int j=i-1;j>0;j--) 
        {
            x|= a[j];
            if(!f[x|a[i]])
            {
                f[x|a[i]]=1;
                ans++;
            }
            if((x|a[i])==x)
                break;
        }
    }
    cout<<ans<<endl;
    return 0;
}