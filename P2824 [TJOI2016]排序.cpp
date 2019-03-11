//暴力踩标算,n方过百万
#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],s[maxn];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    while(m--)
    {
        int L=0x7fffffff,R=0;
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        for(int i=l;i<=r;i++)
            s[a[i]]=1,L=min(L,a[i]),R=max(R,a[i]);
        int p=l;
        if(op==0)
        {
            for(int i=L;i<=R;i++)
                if(s[i]) 
                    a[p++]=i,s[i]=0;
        }
        else 
        {
            for(int i=R;i>=L;i--)
                if(s[i]) 
                    a[p++]=i,s[i]=0;
        }
    }
    int q;
    scanf("%d",&q);
    printf("%d\n",a[q]);
    return 0;
}