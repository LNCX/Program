#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],p,flag=1;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==n) p=i;
    }
    for(int i=p;i>1;i--)
        if(a[i]<a[i-1])
            flag=0;
    for(int i=p;i<n;i++)
        if(a[i]<a[i+1])
            flag=0;
    flag?puts("YES"):puts("NO");
    return 0;
}