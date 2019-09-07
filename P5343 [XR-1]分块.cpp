#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=1e9+7;
int n,f[105];
vector<int>a; 
namespace read
{
    map<int,int>ma;
    void main()
    {
        scanf("%lld",&n);
        int m;
        scanf("%lld",&m);
        for(int i=1;i<=m;i++)
        {
            int x;
            scanf("%lld",&x);
            ma[x]++;
        }
        scanf("%lld",&m);
        for(int i=1;i<=m;i++)
        {
            int x;
            scanf("%lld",&x);
            if(ma[x]==1) a.push_back(x),ma[x]++;
        }
        for(auto i:a)
            f[i]++;
    }
}
struct mat
{
    static const int N=105,len=100;
    int d[N][N];
    mat(){memset(d,0,sizeof(d));}
    void make()
    {
        for(int i=1;i<=len;i++)
            d[1][i]=1;
        for(int i=2;i<=len;i++)
            d[i][i-1]=1;
    }
    void id()
    {
        for(int i=1;i<=len;i++)
            d[i][i]=1;
    }
    friend mat operator*(const mat a,const mat b)
    {
        mat c;
        for(int k=1;k<=len;k++)
            for(int i=1;i<=len;i++)
                for(int j=1;j<=len;j++)
                    (c.d[i][j]+=a.d[i][k]*b.d[k][j])%=mod;
        return c;
    }
    void print()
    {
        for(int i=1;i<=len;i++)
        {
            for(int j=1;j<=len;j++)
                printf("%lld ",d[i][j]); 
            puts("");
        }
    }
};
mat power(mat a,int b)
{
    mat res; 
    res.id();
    while(b)
    {
        if(b&1) res=res*a;
        b>>=1,a=a*a;
    } 
    return res;
}
signed main()
{
    read::main();
    sort(a.begin(),a.end());
    if(n<=100)
    {
        for(int i=1;i<=n;i++)
            for(auto j:a)
                if(i-j>=0)
                    (f[i]+=f[i-j])%=mod;
        cout<<f[n]<<endl;
        exit(0);
    }
    else
    {
        mat b;
        b.make();
        mat c=power(b,n-100);
        int ans=0;
        for(int i=1;i<=100;i++)
            (ans+=c.d[1][i]*f[i])%=mod;
        cout<<ans<<endl;
    }
}
