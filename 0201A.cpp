#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1000000007LL;
int n,x,t[110];
struct mat
{
    LL a[110][110];
    mat()
    {
        memset(a, 0, sizeof(a));
        for(int i=1;i<=101;i++)
            a[i][i]=1;
    }
}; 
mat operator * (mat a, mat b)
{
    mat ret;
    for(int i = 1; i <= 101; i++)
        for(int j = 1; j <= 101; j++)
        {
            ret.a[i][j] = 0;
            for(int k = 1; k <= 101; k++)
                ret.a[i][j] = (ret.a[i][j] + a.a[i][k]*b.a[k][j] % mod) % mod;
        }
    return ret;
}
mat quick_pow(mat a, int b)
{
    mat I;
    while(b)
    {
        if(b & 1)
            I = I*a;
        a = a*a;
        b >>= 1;
    }
    return I;
}
LL dp[110];
int main()
{
    scanf("%d %d", &n, &x);
    int tt;
    memset(t, 0, sizeof(t));
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &tt);
        t[tt]++;
    }
    mat A;
    memset(A.a, 0, sizeof(A.a));
    for(int i = 1; i <= 100; i++)
        A.a[i][1] = A.a[i][101] = t[i];
    for(int i = 1; i < 100; i++)
        A.a[i][i + 1] = 1;
    A.a[101][101] = 1;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= 100; i++)
        for(int j = 1; i - j >= 0 && j <= 100; j++)
            dp[i] = (dp[i - j]*t[j] + dp[i]) % mod;
    if(x <= 100)
    {
        LL ans = 0;
        for(int i = 0; i <= x; i++) ans = (ans + dp[i]) % mod;
        cout<<ans<<endl;
        return 0;
    }
    A = quick_pow(A, x - 99);
    LL S = 0;
    for(int i = 0; i <= 99; i++) S = (S + dp[i]) % mod;
    LL ans = 0;
    for(int i = 1; i <= 100; i++)
        ans = (ans + dp[100 - i]*A.a[i][101]) % mod;
    ans = (ans + S*A.a[101][101]) % mod;
    cout<<ans<<endl;
    return 0;
}