#include<bits/stdc++.h>
const int N=1e5+5;
using namespace std;
int p,a[N];
int main()
{
    int n,ans=1;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    if(a[2]>=a[1]) p=1;
    for(int i=1;i<=n;i++)
    {
        if(p==0&&i==n) {ans++;break;}
        if(p==1) if(a[i+1]<a[i]){ans++;p=0;continue;}
        if(p==0) if(a[i+1]>a[i]) {ans++;p=1;continue;}
    }
    cout<<ans<<endl; 
}