#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=105;
int a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        if(i%2) printf("%d ",a[i]);
    for(int i=n;i>=1;i--)
        if(i%2==0) printf("%d ",a[i]);
    return 0;
}