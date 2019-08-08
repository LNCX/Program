#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e4+5,MOD=19260817,base=31;
int h[N];
ll mi[N],u[N],v[N];
char s[N];
ll gethash(int l,int r)
{
    ll ans=0;
    ans=h[r]-h[l-1]*mi[r-l+1];
    ans%=MOD;ans+=MOD;ans%=MOD;
    return ans;
}
void work()
{
    int zuo,you;
    memset(h,0,sizeof(h));
    memset(u,0,sizeof(u));
    memset(v,0,sizeof(v));
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)h[i]=(h[i-1]*base+s[i])%MOD;
    for(int L=1;L*2<=len;L++)
    {
        for(int i=L+L;i<=len;i+=L)
        {
            int pre=i-L;
            if(s[i]!=s[pre])continue;
            int l=1,r=L,tmps=0;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(gethash(pre-mid+1,pre)==gethash(i-mid+1,i))l=mid+1,tmps=mid;
                else r=mid-1;
            }
            l=1,r=L;int tmpp=0;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(gethash(pre,pre+mid-1)==gethash(i,i+mid-1)) l=mid+1,tmpp=mid;
                else r=mid-1;
            }
            if(tmps+tmpp>L)
            {
                u[pre-tmps+1]++;u[pre+tmpp-L+1]--;
                v[i-tmps+L]++;v[i+tmpp]--;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=len;i++)
        u[i]+=u[i-1],v[i]+=v[i-1];   
    for(int i=1;i<len;i++) ans+=v[i]*u[i+1];
    printf("%lld\n",ans);
}
int main()
{
    int t;
    mi[0]=1;for(int i=1;i<=30002;i++)mi[i]=(mi[i-1]*base)%MOD;
    scanf("%d",&t);
    while(t--)work();
    return 0;
} 