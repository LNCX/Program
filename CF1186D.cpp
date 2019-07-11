#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
double a[maxn];
int ans=0,b[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%lf",&a[i]);
    for(int i=1;i<=n;i++)
        ans+=(b[i]=ceil(a[i]));
    for(int i=1;i<=n;i++)
    {
        if(ans>0)
        {
            if(b[i]==a[i])
            {
                printf("%d\n",b[i]);
                continue;
            }
            printf("%d\n",b[i]-1);
            ans--;
        }
        else printf("%d\n",b[i]);
    }
    return 0;
}