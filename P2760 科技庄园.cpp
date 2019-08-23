#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e2+5;
int n,m,v[N],c[N],a[M][M],f[N],t,e,q=0,s;
int main()
{
    cin>>n>>m>>t>>e;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>s;
            int t=1,x=2*(i+j);
            if(a[i][j])
            {
                while(s>=t)
                {
                    c[++q]=t*x;
                    v[q]=t*a[i][j];
                    s-=t;t*=2;
                }
                c[++q]=x*s;
                v[q]=s*a[i][j];
            }
        }
    t=min(t,e-1);
    for(int i=1;i<=q;i++)
        for(int j=t;j>=c[i];j--)
            f[j]=max(f[j],f[j-c[i]]+v[i]);
    cout<<f[t]<<endl;
    return 0;
}