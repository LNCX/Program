#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(){}
template<typename T,typename... Ts>
inline void read(T &arg,Ts&... args)
{
    T x=0,f=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c-'0');c=getchar();}
    arg=x*f;
    read(args...);
}
const int N=1e5+5;
ll a[N],b[N];
int main()
{
    int n,m;
    read(n,m);
    for(int i=1;i<=n;i++) read(a[i]);
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        for(int i=l;i<=r;i++) b[i]=a[i];
        sort(b+l,b+r+1);
        ll cnt=1,now=1,ans=b[l];
        for(int i=l+1;i<=r;i++)
        {
            cnt++;
            if(b[i]!=b[i-1]) now=cnt;
            ans+=b[i]*now;
        }     
        printf("%lld\n",ans);
    }
    return 0;
}