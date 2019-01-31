#include<bits/stdc++.h>
using namespace std;
const int mod=10;
struct lint
{
    int num[10005];
    int len;
    friend lint operator*(const lint &a,const lint &b)
    {
        lint ans;ans.len=a.len+b.len;
        memset(ans.num,0,sizeof(ans.num));
        for(int i=1;i<=a.len;i++)
            for(int j=1;j<=b.len;j++)
            {
                ans.num[i+j-1]+=a.num[i]*b.num[j];
                ans.num[i+j]+=ans.num[i+j-1]/mod;
                ans.num[i+j-1]%=mod;
            }
        while(ans.len>1&&ans.num[ans.len]==0) ans.len--;
        return ans;
    }
    friend lint operator-(const lint &a,int b)
    {
        lint ans=a;
        for(int i=1;i<=a.len;i++)
        {
            ans.num[i]-=b;
            if(ans.num[i]<0)
            {
                ans.num[i+1]-=1;
                ans.num[i]+=10;
            }
        }
        while(ans.len>1&&ans.num[ans.len]==0) ans.len--;
        return ans;
    }
}a,b,ans;
int main()
{
    // 2^(a+1)-2
    int n;
    cin>>n;n++;
    a.num[1]=2,ans.num[1]=1;
    a.len=1,ans.len=1;
    while(n)
    {
        if(n%2) ans=ans*a;
        a=a*a;
        n>>=1;
    }
    a=a-2;
    for(int i=a.len;i>=1;i--)
        printf("%d",a.num[i]);
    puts("");
}