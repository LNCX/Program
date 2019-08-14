#include<bits/stdc++.h>
using namespace std;
const int N=505;
int a[N];
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        n=4*n;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        bool f=1;
        int ans=a[1]*a[n];
        for(int i=1,j=n;i<=n/2;i+=2,j-=2)
        {
            if(a[i]!=a[i+1]||a[j]!=a[j-1]||a[j]*a[i]!=ans)
            {
                f=0;
                break;
            }
        }
        f?puts("YES"):puts("NO");
    }
    return 0;
}