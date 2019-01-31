#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a,b,p;
void Exgcd(LL a,LL b,LL &d,LL &x,LL &y)
{
    if(!b){d=a;x=1;y=0;return;}
    Exgcd(b,a%b,d,y,x);//反向操作
    y-=x*(a/b);
}
void solve1()
{
    a%=p;
    LL ans=1;
    while(b)
    {
        if(b%2) ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    printf("%lld\n",ans);
}
void solve2()
{
    LL d,x,y;
    Exgcd(a,p,d,x,y);
    if(b%d) printf("Orz, I cannot find x!\n");
    else printf("%lld\n",((x*b/d)%p+p)%p);
}
map<LL,LL>mp;
void solve3()
{
    a%=p;
    mp.clear();
    LL m=ceil(sqrt(p)),tmp=1;
    mp[1]=m+1;
    for(LL j=1;j<m;j++)
    {
        tmp=tmp*a%p;
        if(!mp[tmp]) mp[tmp]=j;
    }
    tmp=tmp*a%p;
    LL d=1,gcd,x,y;
    for(LL i=0;i<m;i++)
    {
        Exgcd(d,p,gcd,x,y);
        if(b%gcd) break;
        x=(b/gcd*x%p+p)%(p/gcd);
        int j=mp[x];
        if(j)
        {
            if(j==m+1) j=0;
            printf("%lld\n",i*m+j);
            return ;
        }
        d=d*tmp%p;
    }
    printf("Orz, I cannot find x!\n");
}
int main()
{
    int t,k;
    scanf("%d%d",&t,&k);
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&p);
        if(k==1) solve1();
        if(k==2) solve2();
        if(k==3) solve3();
    }
}