#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],f[N];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),f[i]=0;
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++)
            f[i]=max(f[i-1],a[i]-f[i-1]);
        cout<<f[n]<<endl;
    }
    return 0;
}