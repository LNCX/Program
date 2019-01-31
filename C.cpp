#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
struct node
{
    int h,d;
    bool operator<(const node x) const
    {
        return h<x.h;
    }
}a[maxn];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].h);
        a[i].d=i; 
        if(a[i].h>=k)
        {
            puts("-1\n0");
            return 0;
        }
    }
    
    return 0;
}