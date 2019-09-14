#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,f[N],v[N],w[N],tot;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        for(int j=1;j<=c;j<<=1)
        {
            w[++tot]=j*a;
            v[tot]=j*b;
            c-=j;
        }
        if(c)
        {
            w[++tot]=c*a;
            v[tot]=c*b;
        }
    }
    for(int i=1;i<=tot;i++)
        for(int j=m;j>=v[i];j--)
            f[j]=max(f[j],f[j-v[i]]+w[i]);
    cout<<f[m]<<endl;
    return 0;
}