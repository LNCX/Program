#include<bits/stdc++.h>
using namespace std;
const int N=105;
int ans,b[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        scanf("%d",&b[i]);
    b[n]=0x3f3f3f3f;
    for(int i=n-1;i>0;i--)
        ans+=min(b[i],b[i+1]);
    ans+=b[1];
    cout<<ans<<endl; 
    return 0;
}