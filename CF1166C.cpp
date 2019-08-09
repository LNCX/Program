#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
long long ans;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),a[i]=abs(a[i]);
    sort(a+1,a+1+n);
    int l=1,r=2;
    while(l<=n&&r<=n)
    {
        while(a[l]<a[r]-a[l]) l++;
        if(l>n) break;
        ans+=(long long)r-l;r++;
    }
    cout<<ans<<endl;
    return 0;
}