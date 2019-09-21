#include<bits/stdc++.h>
#define int long long 
using namespace std;
int sum[]={0,45,9045,1395495,189414495,23939649495,2893942449495,339393974949495,38939394344949495};
int num[]={0,9,189,2889,3889,488889,5888889,68888889,788888889};
signed main()
{
    int q;
    scanf("%lld",&q);
    while(q--)
    {
        int k,x;
        scanf("%lld",&k);
        for(int i=8;i>=0;i--)
            if(k>=sum[i]) 
            {
                x=i;
                break;
            }
        k-=sum[x];
        
    }
    return 0;
}