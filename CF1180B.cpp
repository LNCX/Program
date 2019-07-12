#pragma GCC optimiz("O2")
#include<bits/stdc++.h>
using namespace std;
int n,a[100005],maxx;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>=0)a[i]=-a[i]-1;
        maxx=min(maxx,a[i]);
    }
    for(int i=1;i<=n&&n&1;i++)
    {
        if(a[i]==maxx)
        {
            a[i]=-a[i]-1;
            break;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}