#include<cstdio>
typedef long long ll;
const int N=110;
int n;
ll a[N],m,k;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld%lld",&n,&m,&k);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(int i=1;i<n&&m>=0;i++)
        {
            ll tmp=a[i+1]-k;
            if(tmp<0)tmp=0;
            m+=a[i]-tmp;
        }
        (m < 0)?puts("NO"):puts("YES");
    }
    return 0;
}