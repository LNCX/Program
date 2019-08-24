#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
unsigned int pw0[50000],pw1[50000];
namespace Mker
{
    #include<climits>
    #define ull unsigned long long
    #define uint unsigned int
    ull sd;int op;
    inline void init() {scanf("%llu %d", &sd, &op);}
    inline ull ull_rand()
    {
        sd ^= sd << 43;
        sd ^= sd >> 29;
        sd ^= sd << 34;
        return sd;
    }
    inline ull rand()
    {
        if (op == 0) return ull_rand() % USHRT_MAX + 1;
        if (op == 1) return ull_rand() % UINT_MAX + 1; 
        if (op == 2) return ull_rand();
    }
}
void make()
{
    pw0[0]=pw1[0]=1;
    for(int i=1;i<=32768;i++)
		pw0[i]=pw0[i-1]*3%mod;
    unsigned t=pw0[32768];
    for(int i=1;i<=32768;i++)
		pw1[i]=1ll*pw1[i-1]*t%mod;
}
int qpower(int n){return 1ll*pw0[n&32767]*pw1[n>>15]%mod;}
int main()
{
    int T;
    scanf("%d",&T);
    Mker::init();
    make();unsigned long long n;int sans=0;
    while(T--)
    {
        n=Mker::rand();
        int ans=281250002ll*(((n&1)?15:-15)+36+qpower(n%(mod-1))*((long long)(n%mod*36%mod)-117)%mod)%mod;
        sans^=(ans+mod)%mod;
    }
    cout<<sans<<endl;
}