#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main()
{
    int n,cnt=0;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        if(a[i]) continue;
        else a[i]=++cnt;
        for(int j=2;i*j<=n;j++)
            a[i*j]=cnt;
    }                
    for(int i=2;i<=n;i++)
        printf("%d ",a[i]);
    puts("");
    return 0;
}