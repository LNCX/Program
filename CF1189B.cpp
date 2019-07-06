#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>a;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    if(a[n-1]<a[n-3]+a[n-2])
    {
        swap(a[n-1],a[n-2]);
        puts("YES");
        for(auto i:a)
            printf("%d ",i);
    }
    else puts("NO");
}