#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
long long a[40]={0,1},b[40]={0,2};
int main()
{
    int t;
    cin>>t;
    for(LL i=2;i<=32;i++)
    {
        a[i]=a[i-1]*4;
        b[i]=b[i-1]*2;
        a[i-1]+=a[i-2];
        b[i-1]+=b[i-2]-1;
    }
    while(t--)
    {
        LL n,k;
        cin>>n>>k;
        if(n>31) printf("YES %lld\n",n-1); 
        else if(k>a[n]) printf("NO\n");
        else
        {
            LL i;
            for(i=1;i<=n;i++)
                if(k>=b[i]&&k<=a[i]+a[n-i]*((1<<i)-1)*((1<<i)-1))
                    break;
            if(i>n) printf("NO\n");
            else    printf("YES %lld\n",n-i); 
        }
    }
}