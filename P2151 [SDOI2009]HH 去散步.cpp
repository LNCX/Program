#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=151,mod=45989;
int n,m,s,t,x[N],y[N],cnt;
LL T;
struct mat
{
    int c[N][N];
    mat()
    {memset(c,0,sizeof(c));}
    mat operator *(const mat&A)
    {
        mat ans;
        for(int i=1;i<=cnt;i++)
        for(int j=1;j<=cnt;j++)
        for(int k=1;k<=cnt;k++)
            ans.c[i][j]=(ans.c[i][j]+c[i][k]*A.c[k][j]%mod)%mod;
        return ans;
    }
}A;
mat pow(mat a,LL b)
{
    mat ans;
    for(int i=1;i<=cnt;i++)
        ans.c[i][i]=1;
    while(b)
    {
        if(b&1)ans=ans*a;
        b>>=1;a=a*a;
    }
    return ans;
}
int main()
{
    scanf("%d%d%lld%d%d",&n,&m,&T,&s,&t);
    s++;t++;
    x[++cnt]=0;y[cnt]=s;
    for(int i=1,u,v;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        u++,v++;
        x[++cnt]=u,y[cnt]=v;
        x[++cnt]=v,y[cnt]=u;
    }
    for(int i=1;i<=cnt;i++)
        for(int j=1;j<=cnt;j++)
            if(i!=j&&i!=(j^1)&&y[i]==x[j])
                A.c[i][j]=1;
    mat Ans=pow(A,T);
    int ans=0;
    for(int i=1;i<=cnt;i++)
        if(y[i]==t)
            ans=(ans+Ans.c[1][i])%mod; 
    cout<<ans<<endl;
    return 0;
} 