#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],sum;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),sum+=a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++)
        if(a[i]==a[i+1])
            return puts("cslnb"),0;
    sum%2?puts("cslnb"):puts("sjfnb");
    return 0;
}