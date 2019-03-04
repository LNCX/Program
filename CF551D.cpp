#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL m;
struct mat
{
    LL a[2][2];
    mat()
    {memset(a,0,sizeof(a));}
    friend mat operator*(mat a,mat b)
    {
        mat c;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j]%m)%m;
        return c;
    }
    friend mat operator^(mat a,LL b)
    {
        mat tmp;
        tmp.a[0][0]=tmp.a[1][1]=1;
        while(b)
        {
            if(b&1)
                tmp=tmp*a;
            a=a*a;
            b>>=1;
        }
        return tmp;
    }
};
LL pow(LL a, LL b)
{
    LL tmp=1;
    while(b)
    {
        if(b&1)
            tmp=tmp*a%m;
        a=a*a%m;
        b>>=1;
    }
    return tmp;
}
int main()
{
    LL n,k,l;
    cin>>n>>k>>l>>m;
    if(l<=61&&k>=(1LL<<l))
    {
        puts("0");
        return 0;
    }
    LL ans=1;
    for(int i=0;i<l;i++)
    {
        mat tmp;
        tmp.a[0][0]=tmp.a[0][1]=tmp.a[1][0]=1;
        tmp.a[1][1]=0;
        LL num=(tmp^(n+1)).a[0][0];
        if(i<=61&&(1LL<<i)&k)
        {
            num=pow(2LL, n)-num;
            num%=m;
        }
        ans=ans*num%m;
        ans=(ans+m)%m;
    }
    cout<<ans%m<<endl;
    return 0;
}