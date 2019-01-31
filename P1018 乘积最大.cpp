#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
char s[maxn];
struct lint
{
    short num[maxn],len;
    friend lint operator*(lint a,lint b)
    {
        lint c;
        memset(c.num,0,sizeof(c.num));
        c.len=a.len+b.len;
        for(int i=1;i<=a.len;i++)
            for(int j=1;j<=b.len;j++)
            {
                c.num[i+j-1]+=a.num[i]*b.num[j];
                c.num[i+j]+=c.num[i+j-1]/10;
                c.num[i+j-1]%=10;
            }
        while(c.len>1&&c.num[c.len]==0) c.len--;
        return c;
    }
    bool operator<(lint x)const
    {
        if(len<x.len) return true;
        if(len>x.len) return false;
        for(int i=len;i>=1;i--)
        {
            if(num[i]<x.num[i]) return true;
            if(num[i]>x.num[i]) return false;
        }
        return false;
    }
};
lint f[maxn][maxn],num[maxn][maxn];//f[i][k]=max{f[l][k-1]*num[l+1][i]}
int main()
{
    int n,k;
    scanf("%d%d%s",&n,&k,s);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            num[i][j].num[1]=s[j-1]-'0';
            for(int k=1;k<=num[i][j-1].len;k++)
                num[i][j].num[k+1]=num[i][j-1].num[k];
            num[i][j].len=num[i][j-1].len+1;
        }
    for(int i=1;i<=n;i++)
        f[i][0]=num[1][i];
    for(int i=1;i<=n;i++)
        for(int l=1;l<i;l++)
            for(int j=1;j<=l&&j<=k;j++)
            {
                lint res=f[l][j-1]*num[l+1][i];
                if(f[i][j]<res)
                    f[i][j]=res;
            }            
    lint ans=f[n][k];
    for(int i=ans.len;i>=1;i--)
        cout<<ans.num[i];
    puts("");
    return 0;
}