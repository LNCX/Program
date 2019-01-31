#include<bits/stdc++.h>
const int maxn=100005;
int f[maxn],a[maxn];
inline int read(){int x;scanf("%d",&x);return x;}
int main()
{
    int n=read();
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++)
        a[read()]=i;
    for(int i=1;i<=n;i++)
    {
        int x=a[read()];
        *std::lower_bound(f+1,f+n+1,x)=x;
    }
    printf("%lld\n",std::lower_bound(f+1,f+n+1,f[0])-f-1);
    return 0;
}