#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e5+5;
LL a[maxn],sum[maxn];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    LL pos=0,tot=0,cnt=n;
    for(int i=2;i<=n;i++)
    {
        tot+=a[i-1]*pos;
        if(tot-(cnt-i+(n-cnt))*a[i]*(i-1-(n-cnt))<k)
        {
            cnt--;
            tot-=a[i]*pos;
            printf("%d\n",i);
        }
        else pos++;
    }
    return 0;
}