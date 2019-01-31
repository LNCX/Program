#include<bits/stdc++.h>
using namespace std;
int len,n;
long long ans,mod;
struct mat
{
    long long d[20][20];
    friend mat operator*(const mat &x,const mat &y)
    {
        mat res;
        memset(res.d,0,sizeof(res.d));
        for(int i=1;i<=len;i++)
        for(int k=1;k<=len;k++)
        for(int j=1;j<=len;j++)
            res.d[i][j]=(res.d[i][j]+x.d[i][k]*y.d[k][j])%mod;
        return res;
    }
}e;
void clear(mat &x){memset(x.d,0,sizeof(x.d));}
void power(mat &a,int m)
{
    mat ans=e;
    while(m)
    {
        if(m&1) 
            ans=ans*a;
        a=a*a;
        m>>=1;
    }
    a=ans;
}
int main()
{
    while(scanf("%d%d%lld",&len,&n,&mod)&&(len||n||mod))
    {
        ans=0;
        mat a,b,c;
        clear(a),clear(b),clear(c);
        for(int i=1;i<=len;i++)
        {
            scanf("%lld",&a.d[1][i]);
            a.d[i+1][i]=1;
            e.d[i][i]=1;
        }
        for(int i=1;i<=len;i++)
            scanf("%lld",&b.d[len-i+1][1]);
        if(n<=len)
        {
            printf("%lld\n",b.d[len-n+1][1]);
            continue;
        }
        power(a,n-len);
        for(int i=1;i<=len;i++)
            ans=(ans+a.d[1][i]*b.d[i][1])%mod;
        cout<<ans<<endl;
    }
}