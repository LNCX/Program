#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,l=0,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a>l)ans+=(a-l);
        l=a;
    }
    printf("%d\n",ans);
}
