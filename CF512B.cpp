//f[gcd(x,y)] = min(f[gcd(x,y)],f[x]+c[y])
#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
int n,l[maxn],c[maxn];
map<int,int>f;
map<int,int>::iterator it;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&l[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
    {
        if(!f[l[i]])
            f[l[i]]=c[i];
        else f[l[i]]=min(f[l[i]],c[i]);
    }
    for(int i=1;i<=n;i++)
       for(it=f.begin();it!=f.end();it++)
        {
            if(it->first==l[i]) continue;
            int t=gcd(l[i],it->first);
            if(!f.count(t)) f[t]=it->second+c[i];
            else f[t]=min(f[t],it->second+c[i]);
        }
    if(!f[1]) puts("-1");
    else printf("%d\n",f[1]);
}