#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[3],d,ans=0;
    scanf("%d%d%d%d",&a[0],&a[1],&a[2],&d);
    sort(a,a+3);
    if(a[2]-a[1]<d) ans+=d-a[2]+a[1];
    if(a[1]-a[0]<d) ans+=d-a[1]+a[0];
    cout<<ans<<endl;
    return 0;
}