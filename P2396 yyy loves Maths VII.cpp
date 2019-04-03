// FJJ AK ZJOI
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
const int mod=1e9+7;
int dis[1<<24],f[1<<24],b[3];
inline int read()
{
    register int x=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c))
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
int main()
{
    int n=read();
    for(register int i=0;i<n;i++) 
        scanf("%d",&dis[1<<i]);
    int m=read();
    while(m--) b[m]=read();
    f[0]=1;
    int nmdp=(1<<n)-1;
    for(register int i=1;i<=nmdp;i++)
    {
        register int j=i&-i;
        dis[i]=dis[i^j]+dis[j];
        if(dis[i]==b[0]||dis[i]==b[1]) continue;
        for(register int k=i,j;k;k^=j)
        {
            j=k&-k;
            f[i]+=f[i^j];
            if(f[i]>=mod) f[i]-=mod;
        }
    }
    printf("%d\n",f[nmdp]);
    return 0;
}