#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        if(a[n-1]==1)puts("0");
        else cout<<min(a[n-1]-1,n-2)<<endl;
    }   
    return 0;
}