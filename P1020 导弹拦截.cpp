#include<bits/stdc++.h>
using namespace std;
int a[100005],f[100005],low[100005];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int n=1;
    while(cin>>a[n])n++;
    n--;
    int ans2=1,ans1=1;
    low[1]=f[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(low[ans1]>=a[i])low[++ans1]=a[i];
        else low[upper_bound(low+1,low+ans1+1,a[i],cmp)-low]=a[i];
        if(f[ans2]<a[i])f[++ans2]=a[i];
        else f[lower_bound(f+1,f+ans2+1,a[i])-f]=a[i];
    }
    cout<<ans1<<"\n"<<ans2;
    return 0;
}