#include<bits/stdc++.h>
using namespace std;
int ans1,ans2;
int main()
{
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0;i<l;i++)
        ans1+=(1<<i);
    ans1+=n-l;
    for(int i=0;i<r;i++)
        ans2+=(1<<i);
    ans2+=(n-r)*(1<<(r-1));
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}