#include<bits/stdc++.h>
using namespace std;
int ans=0;
int main()
{
    int y,b,r;
    scanf("%d%d%d",&y,&b,&r);
    if(y+1<=b&&y+2<=r) ans=max(ans,3*y+3);
    if(b-1<=y&&b+1<=r) ans=max(ans,3*b);
    if(r-1<=b&&r-2<=y) ans=max(ans,3*r-3);
    cout<<ans<<endl;
    return 0;
}